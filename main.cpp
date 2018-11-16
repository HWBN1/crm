#include<iostream>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<vector>
#include<Windows.h>
#include <conio.h>
#include"Car.h"
#include"Customer.h"
#include"Invoice.h"

using namespace std;
vector<Car> car;
vector<Invoice> invoice;
vector<Customer> customer;
int idInvoice=0, numberCar, totalCash = 0;
void MainMenu();
void admin();
void invoiceInfor();
void printInvoice(int id);
void Exit();
void Gotoxy(int, int);
void CheckInvoice();
void loading();

void ccolor(int clr){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, clr);
}

void loading()
{
	ccolor(2);
	Gotoxy(40,15);
	cout << "%";
	int load = 0;
	for (int i=22; i<=52; i+=3)
	{	
		Gotoxy(37,15);
		ccolor(2);
		cout << load;
		load += 10;
		Gotoxy(i,17);
		ccolor(26);
		cout << "   ";
		Sleep(200);
	}
	Sleep(500);
}

void pwellcome(char welcome[50], char welcome2[50], char welcome3[50], char welcome4[50]){
	ccolor(26);
	/*="WELCOME TO";
	char welcome2[50]="CAR RENTAL";
	char welcome3[50]="MANAGEMENT SYSTEM";
	char welcome4[50]="by U3D TEAM";*/
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){
		printf(" %c",welcome[wlc]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){
		printf(" %c",welcome2[wlc2]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		printf(" %c",welcome3[wlc3]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t\t ");
	for(int wlc4=0; wlc4<strlen(welcome4) ;wlc4++){
		printf(" %c",welcome4[wlc4]);
		Sleep(100);
	}
}
int compare(char* str1, char* str2)	//So sanh 2 chuoi (so sanh mat khau)
{
	for(int i = 0;i<7;i++)
	{
		if(str1[i]!=str2[i]) return 0;
	}
	return 1;
}

void Gotoxy(int x,int y)
{
	static HANDLE h=NULL;
	if(!h)
		h=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c={x,y};
	SetConsoleCursorPosition(h,c);

}
void CarList() //Hien thi danh sach xe
{
	system("cls");
	cout << endl << setfill (' ') << setw (20) << "\t\t\tCAR LIST" ;
	cout<<endl<<endl;
	cout<<"\t";
	cout << setfill ('-') << setw (65) << "-" ;
	cout <<" "<< endl;
	cout << "\t|";
	cout << setfill(' ') <<setw(2) <<" " <<"| "<<setfill(' ')<< setw(20) << left << "Item Name" << " | " << "Price" <<"| " << "    Seat" <<"\t"<<"| " << "  Quantity" << "\t|";// <<"\t";
	cout<<endl;

	for(int i=0 ; i < car.size();i++)
	{
		cout<<"\t";
		cout << setfill ('-') << setw (65) << "-" ;
		cout <<" "<< endl;
		cout << "\t|";
		cout << setfill(' ') <<setw(2) << i+1 <<"| "<<setfill(' ')<< setw(20) << left << car[i].getName() << " | " << car[i].getFee() <<"\t"<<" |\t" << car[i].getSeat() <<"\t"<<"|\t" << car[i].getLeft() << "\t|";// <<"\t";
		cout<<endl;
	}
	cout<<"\t";
	cout << setfill ('-') << setw (65) << "-" ;
}

void invoiceInfor()//Nhap thong tin hoa don
{
	int id;
	cout << endl << endl << "\tSelect car ID: ";
	cin >> id;
	car[id-1].setLeft(car[id-1].getLeft()-1);

	char* name = new char[50];
	char* phone = new char[15];
	char* address = new char[100];

	cout<<"\tYour name: ";
	cin.getline(name, 50);
	cin.getline(name, 50);
	cout <<"\tYour phone: ";
	cin.getline(phone, 15);
	cout <<"\tYour address: ";
	cin.getline(address, 100);

	Customer cu(name, phone, address);
	customer.push_back(cu);

	int day;
	cout<<"\tHow long do you want to rent this car? ";
	cin >> day;
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int time_day = ltm->tm_mday;
	int time_month = 1+ ltm->tm_mon;
	int time_year = 1900 +ltm->tm_year;
	char func;

	cout << endl <<"\tPLEASE CONFIRM YOUR ORDER (Y/N): " ;
	cin >> func;
	if (func == 'Y' || func == 'y') {
		Invoice in(idInvoice, day, time_day,time_month,time_year,car[id-1],cu);
		invoice.push_back(in);

		ofstream outfile("Invoice.txt", ios::out);
		outfile<<in.getCustomer().getName()<<endl;
		outfile<< in.getCar().getName()<<endl;
		outfile<< in.getRentMonth()<<endl;
		outfile<< in.getRentMonth()<<endl;
		outfile<<in.getRentYear()<<endl;
		outfile<< in.getDay()*in.getCar().getFee()<<endl;
		outfile.close();


		idInvoice++;
		system("cls");
		Gotoxy(5,15);
		cout << endl << "\t\t\tTHANK YOU >>> SUCCESSFULLY ORDERED!!!" << endl;
		Sleep(1000);
		printInvoice(idInvoice-1);
	}
	else {
		MainMenu();
	}
}

void printInvoice(int id)		//in hoa don
{	
	int size = invoice.size();
	if (id < 0 || id >= size) {
		Gotoxy(20,7);
		cout << "WRONG INVOICE ID ..." << endl;
		Sleep(2000);
		CheckInvoice();
	}
	else {
		Invoice in = invoice[id];
		system("cls");
		Gotoxy(20,5);
		cout <<"YOUR INVOICE"<<endl;

		Gotoxy(20,7);
		cout << setfill ('-') << setw (44) << "-" ;
		cout <<" "<< endl;

		Gotoxy(20,9);							  
		cout<<"ID:";
		Gotoxy(50,9);
		cout << in.getId();
		Gotoxy(20,11);
		cout << "Name of customer:";
		Gotoxy(50,11);
		cout << in.getCustomer().getName()<<endl;
		Gotoxy(20,13);
		cout<<"Car:" ;
		Gotoxy(50,13);
		cout << in.getCar().getName()<<endl;
		Gotoxy(20,15);
		cout<<"Rent day:";
		Gotoxy(50,15);
		cout << in.getRentDay()<<"/"<< in.getRentMonth()<<"/"<<in.getRentYear()<<endl;
		Gotoxy(20,17);
		cout<<"Return day:" ;
		Gotoxy(50,17);
		cout<< in.getRentDay()+in.getDay()<<"/"<< in.getRentMonth()<<"/"<<in.getRentYear()<<endl;
		Gotoxy(20,19);
		cout<< "Price:";
		Gotoxy(50,19);
		cout << in.getDay()*in.getCar().getFee()<<endl;
		cout<<endl;

		Gotoxy(20,21);

		cout << setfill ('-') << setw (44) << "-" ;
		cout <<" "<< endl;
		Gotoxy(20, 24);
		cout << "NOTICE: REMEMBER YOUR ID TO CHECK YOUR ORDER LATER!!!" << endl;
		char func;
		Gotoxy(20,27);
		cout << "Back to main menu ? (Y/N) ";
		cin >> func;
		if (func == 'Y' || func ==  'y') {
			MainMenu();
		}
		else {
			Exit();
			return;
		}
	}
}

void editInfor()  //edit car's information
{
	CarList();
	int id;
	cout<<endl;
	cout <<"\tEnter car's ID: ";
	cin >> id;
	char* name = new char;
	int fee;
	int seat;
	int left;
	cout<<"\tName:\t" << car[id-1].getName()<<" ---> " ;  cin.ignore();cin.getline(name, 50);car[id-1].setName(name);
	cout<<"\tFee:\t" << car[id-1].getFee()<<" ---> ";  cin>>fee;	car[id-1].setFee(fee) ;
	cout<<"\tSeat:\t" << car[id-1].getSeat()<<" ---> ";  cin>>seat; car[id-1].setSeat(seat);
	cout<<"\tLeft:\t" << car[id-1].getLeft()<<" ---> ";cin>>left;	car[id-1].setLeft(left);

	system("cls");
	Gotoxy(20, 20);
	cout << "SUCCESSFULLY CHANGED";
	Sleep(500);
}

void addCar()
{
	CarList();
	Gotoxy(8,23);
	cout << "ADD NEW CAR" << endl;
	char* name = new char; //ten xe
	int fee;			   // gia
	int seat;			   // so cho
	int left;			   // so luong

	cout<<"\tName:\t";  cin.ignore();cin.getline(name, 50);
	cout<<"\tFee:\t";  cin>>fee;
	cout<<"\tSeat:\t";  cin>>seat;
	cout<<"\tLeft:\t";  cin>>left;
	Car cr(name, fee, seat, left);
	car.push_back(cr);
	numberCar++;
	ofstream outfile("Car.txt",ios::out);
	outfile << numberCar << endl;
	for(int i = 0; i<car.size(); i++)
	{
		char* name = new char[50];
		int fee;
		int seat;
		int left;
		outfile << car[i].getName() << endl;
		outfile << car[i].getFee() << endl;
		outfile << car[i].getSeat() << endl;
		outfile << car[i].getLeft() << endl;
	}
	outfile.close();
	system("cls");
	Gotoxy(20, 20);
	cout << "SUCCESSFULLY CHANGED" << endl;
	Sleep(1000);
	return;
	//admin();
}

void deleteCar()   //Xoa xe
{
	system("cls");
	cout<<setfill(' ')<<setw(40)<<"DELETE CAR: "<<endl;
	CarList();
	int id;
	cout<<endl;
	cout << "\tEnter '0' to exit" << endl;
	cout <<"\tEnter car's ID: ";
	cin >> id;
	if(id == 0)
	{
		return;
	}
	else if(id>numberCar)
	{
		cout<<"This ID is not exist!"<< endl;
		return;
	}
	else
	{
		id--;
		car.erase(car.begin()+id);
	}
	numberCar--;
	ofstream outfile("Car.txt",ios::out);
	outfile << numberCar << endl;
	for(int i = 0; i<car.size(); i++)
	{
		
		outfile << car[i].getName() << endl;
		outfile << car[i].getFee() << endl;
		outfile << car[i].getSeat() << endl;
		outfile << car[i].getLeft() << endl;
	}
	outfile.close();
	system("cls");
	Gotoxy(20, 20);
	cout << "SUCCESSFULLY CHANGED";
	Sleep(1000);
	//admin();
	return;
}

void sumCash()
{
	Gotoxy(5,21);
	cout << "Total cash:\t\t" << totalCash<< "$" <<endl;
	Sleep(2000);
	admin();
}

void admin()
{
	system("cls");
	char* pass = "1234567";
	char* password = new char;
	Gotoxy(20,2);
	cout << setfill ('-') << setw (40) << "-" ;
	cout <<" "<< endl;
	Gotoxy(20,13);
	cout << setfill ('-') << setw (40) << "-" ;
	cout <<" "<< endl;
	Gotoxy(20,8);
	cout<<"Enter pass word: ";
	cin.ignore();
	cin.getline(password, 8); 
	if(compare(pass, password))  //neu dung password
	{  
		int item = -1;
		while(item!=5)
		{	 
			system("cls");
			Gotoxy(20,4);
			cout <<"ADMIN"<<endl;

			Gotoxy(20,6);
			cout << setfill ('-') << setw (40) << "-" ;
			cout <<" "<< endl;

			Gotoxy(20,8);
			cout << "Select your choice: "<<endl;
			Gotoxy(20,10);
			cout << "1 - Add new car" <<endl;
			Gotoxy(20,12);
			cout <<"2 - Edit information" << endl;
			Gotoxy(20,14);
			cout <<"3 - Delete information" << endl;
			Gotoxy(20,16);
			cout <<"4 - Total Cash" << endl;
			Gotoxy(20,18);
			cout <<"5 - Exit" << endl;
			Gotoxy(20,20);
			cout << setfill ('-') << setw (40) << "-" ;
			cout <<" "<< endl;
			Gotoxy(20,22);
			cout<<"YOUR CHOICE: ";
			cin >> item;
			switch(item)
			{	  
			case 1:
				addCar();
				break;
			case 2:
				editInfor();
				break;
			case 3:
				deleteCar();
				//getch();
				break;
			case 4:
				sumCash();
				break;
			default:
				break;
			}
		}
	}
	else	  //neu sai password
	{
		system("cls");
		cout<<"Password is not correct!"<<endl;
		Sleep(1000);
		MainMenu();
	}
}

void CheckInvoice() {
	system("cls");
	Gotoxy(20,1);
	cout << "CHECK YOUR INVOICE" << endl;
	Gotoxy(20,3);
	cout << setfill ('-') << setw (40) << "-" ;
	cout <<" "<< endl;
	int id;
	Gotoxy(20, 5);
	cout << "Enter '-1' to back to Main menu!" << endl;
	Gotoxy(20,7);
	cout<<"Enter your ID Invoice: ";
	cin >> id;
	if (id == -1) {
		return;
	}
	else {
		printInvoice(id);
	}
}

void MainMenu(){
	ccolor(26);
	int func = -1;
	while(func!=4)
	{
		system("cls");
		Gotoxy(20,1);
		cout << "MENU " << endl;
		Gotoxy(20,3);
		cout << setfill ('-') << setw (40) << "-" ;
		cout <<" "<< endl;
		Gotoxy(20,13);
		cout << setfill ('-') << setw (40) << "-" ;
		cout <<" "<< endl;
		Gotoxy(20,5);
		cout <<"1 - Car List"  <<endl;
		Gotoxy(20,7);
		cout<<"2 - Check Your Invoice";
		Gotoxy(20,9);
		cout << "3 - Admin Panel" << endl;
		Gotoxy(20,11);
		cout << "4 - Exit" << endl;
		Gotoxy(20, 15);
		cout << "YOUR CHOICE:   ";
		cin >> func;

		switch(func) {
		case 1:
			CarList(); 
			invoiceInfor();
			break;
		case 2:
			CheckInvoice();
			break;
		case 3:
			admin();
			break;
		case 4:
			Exit();
			return;
		}
	}
}

void Exit() {
	system("cls");
	pwellcome("THANK YOU", "FOR USING", "OUR SERVICE", "by U3D TEAM");
	
	Sleep(500);
	system("cls");
	exit(0);
	//system("pause");
}

int main() {
	//Resize console window
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1000, 600, TRUE);

	//input car's data from file to vector
	ifstream infile("Car.txt",ios::in);
	infile >> numberCar;
	for(int i = 0; i<numberCar; i++)
	{
		char* name = new char[50];
		int fee;
		int seat;
		int left;
		infile.ignore();
		infile.getline(name, 50);
		infile >> fee >> seat >> left;
		Car ca(name, fee, seat, left);
		car.push_back(ca);
	}
	infile.close();

	pwellcome("WELCOME TO", "CAR RENTAL", "MANAGEMENT SYSTEM", "by U3D TEAM");
	loading();
	MainMenu();

	return 0;
}