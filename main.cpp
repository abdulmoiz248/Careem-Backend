#include<iostream>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
void loading();
void header();
int menu();
void login();
void signup();
ifstream in;
ofstream out;
void control();
int location();
int vehicle();
int main()
{

in.open("data.txt");
out.open("data.txt",ios::app);
    header();

label:switch(menu())
{
case 1:
   login();
    break;
case 2:
   signup();
   goto label;
    break;
case 3:
     return 0;
    break;
default:
   cout<<"Invalid Extension..!!!"<<endl;
   goto label;
   break;
}
}
int menu()
{
    cout<<endl;
    int ext;
    cout<<" 1 : Login"<<endl;
    cout<<" 2 : Sign-up"<<endl;
    cout<<" 3 : Exit"<<endl;
    cout<<"Your Extension#";
    cin>>ext;
    return ext;
}
void header()
{
    cout<<endl;
 cout<<"                         *****************************************************"<<endl;
 cout<<"                         "<<"*     ____   ___   ____    ___   ___   _     _      *"<<endl;
 cout<<"                         "<<"*     |   | |   | |   |   |     |     | \\   / |     *"<<endl;
 cout<<"                         "<<"*     |     |   | |___|   |     |     |  \\_/  |     *"<<endl;
 cout<<"                         "<<"*     |     |___| |   \\   |---  |---  |       |     *"<<endl;
 cout<<"                         "<<"*     |     |   | |    \\  |     |     |       |     *"<<endl;
 cout<<"                         "<<"*     |___| |   | |    |  |___  |___  |       |     *"<<endl;
 cout<<"                         *                                                   *"<<endl;
 cout<<"                         *****************************************************"<<endl;
 cout<<endl;
cout<<endl;
 loading();
}
void loading()
{
    int bckbar = 177;
	int bar1 = 219;
	char c = bar1;
	char b = bckbar;
	cout<< "   \t\t\t\t";
	for (int a = 1; a <= 35; a++)
	{
		cout << b;
	}
	cout << "\r";
	cout << "   \t\t\t\t";
	cout << " ";
	for (int i = 1; i <= 35; i++)
	{
		cout << c;
		Sleep(150);
	}
}
void signup()
{
cout<<endl;
   string username;
   string password;
   string number;
   cin.ignore();
   cout<<"Enter Your Name: ";
   getline(cin,username);

   cout<<"Enter Your Password: ";
   getline(cin,password);

   cout<<"Enter Your Number: ";
   getline(cin,number);
  // cin.ignore();
   out<<username<<" "<<password<<" "<<number<<endl;
   cout<<endl;
}
void login()
{
    string name,pass,no;
    string name_check,pass_check;
    cin.ignore();
   lol:cout<<"Enter Your Name: ";
   getline(cin,name_check);
   cout<<"Enter Your Password: ";
   getline(cin,pass_check);
   int alt=0;
    while(in)
    {
        in>>name;
        in>>pass;

        if(name==name_check)
           {

                 if(pass_check==pass)
                       {
                           alt=0;
                           break;
                       }
           }

        in>>no;
        in.ignore();
        alt++;
    }
    in.clear();
    in.seekg(0);
    if(alt==0)
    {
     system("CLS");
     header();
     control();
    }
    else
    {
        cout<<"Invalid Username or Password..!!"<<endl;
        goto lol;
    }
}
void control()
{
    string name;
    int gari;
   int dis=location();
   int autto=vehicle();
    int fare=dis*10+120+autto*3;
   ifstream in2("driver.txt");
   int select=1;
   while(in2)
   {
     in2>>gari;
     in2>>name;
      if(gari==autto)
      {
          cout<<select<<" Driver Name: "<<name<<" Fare: "<<fare<<endl;
          select++;
      }
      in2.ignore();
   }
   cout<<"Your Driver#";
   cin>>select;
   cout<<"Your Driver is On its way...!!"<<endl;
   loading();
   cout<<endl;
   cout<<"Your Fare is: "<<fare<<endl;
}

int vehicle()
{
    cout<<endl;
    cout<<"1 : Motorbike"<<endl;
    cout<<"2 : Car"<<endl;
    cout<<"3 : Auto"<<endl;
    hehe:cout<<"Your Vehicle#";
    int x;
    cin>>x;
    if(x>0 && x<4)
    return x;
    else
    {
        cout<<"Invalid Convience..!!"<<endl;
        goto hehe;
    }
}
int location()
{
 cout<<endl;
 cout<<"Select Your Destination: "<<endl;
 cout<<"1 : Bahria Town "<<endl;
 cout<<"2 : Lake City"<<endl;
 cout<<"3 : Gulberg"<<endl;
 cout<<"4 : Station"<<endl;
 cout<<"5 : Airport"<<endl;
xd:cout<<"Your Destination#";
int x;
cin>>x;
if(x>0 && x<6)
return x;
else
{
    cout<<"Invalid Destination..!!"<<endl;
    goto xd;
}
}
