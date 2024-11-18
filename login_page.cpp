#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot_pass();

int main()
{
    int c;
    cout<<"\t\t\t______________________________________________________________________\n\n\n";
    cout<<"\t\t\t                                  Welcome to the login page           \n\n\n";
    cout<<"\t\t\t                                             MENU                     \n\n\n";
    cout<<"\t\t\t__________________________________                         ____________\n\n";
    cout<<"                                                                             \n\n";
    cout<<"\t|  Press 1 to LOGIN                                      |"<<endl;
    cout<<"\t|  Press 2 to REGISTER                                   |"<<endl;
    cout<<"\t|  Press 3 if you forgot your password                   |"<<endl;
    cout<<"\t|  Press 4 to EXIT                                       |"<<endl;
    cout<<"\t\t\t  Please enter your choice :  ";
    cin>>c;
    cout<<endl;

    switch(c)
    {
        case 1:
             login();
             break;
        
        case 2:
             registration();
             break;

        case 3:
             forgot_pass();
             break;

        case 4:
             cout<<"\t\t\t  Thankyou!  \n\n";
             break;
        
        default:
             system("cls");
             cout<<"\t\t\t Please select from the options given below \n"<<endl;
             main();
    }

}

  void login()
  {

    int count;
    string userId, password, Id, pass;
    system("cls");
    cout<<"\t\t\t Please enter the username and password  : "<<endl;
    cout<<"\t\t\t  USERNAME  ";
    cin>>userId;
    cout<<"\t\t\t  PASSWORD  ";
    cin>>password;

    ifstream input("record.txt");

    while(input>>Id>>pass)
    {
        if(Id==userId && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1)
    {
        cout<<userId<<"\n YOUR LOGIN is successfull \n THANKS for logging in !\n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password\n";
        main();
    }
}
  

  void registration()
  {
   string ruserId,rpassword,rId,rpass;
   system("cls");
   cout<<"\t\t\t  ENTER the username : ";
   cin>>ruserId;
   cout<<"\t\t\t ENTER the password  : ";
   cin>>rpassword;

   ofstream f1("record.txt", ios::app);
   f1<<ruserId<<' '<<rpassword<<endl;
   system("cls");
   cout<<"\t\t\t Registration is Successfull! \n";
   main();
  }
void forgot_pass()
{
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password!No worries \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go to the  main menu "<<endl;
    cout<<"\t\t\t Enter your Choice :";
    cin>>option;
    switch(option)
      {
        case 1:
        {
            int count=0;
            string suserId,sId,spass;
            cout<<"\t\t\tEnter username which you have remembered :";
            cin>>suserId;

            ifstream f2("record.txt");
            while(f2>>sId>>spass)
            {
                if(sId==suserId)
                {
                    count=1;
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"\n\n your account is found \n";
                cout<<"\n\n your Password is : "<<spass;
                main();
            }
            else{
                cout<<"\n\t Sorry your account is not found \n";
            }
            break;
        }
        case 2 :
           {
                main();
                }

            default:
                cout<<"\t\t\t Wrong choice ! please ry again "<<endl;
                forgot_pass();  
      }
}
