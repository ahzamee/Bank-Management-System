#include<iostream>
#include<windows.h>
#include<cstring>
#include<conio.h>
#include<time.h>
using namespace std;

class Bank_System
{
private:
    char *name;
    char *Address;
    string password;
    int Account_num;

public:
    int Balance;
    Bank_System();
    Bank_System(char *m_name,char *m_Address,string m_password,int m_Account_num,int m_Balance);
    int get_account_num()
    {
        return Account_num;
    }
    int get_balance()
    {
        return Balance;
    }
    void View_account();
    void New_account();
    void show_info();
    void show_info(char *m_name,char *m_Address,string m_password,int m_Account_num,int m_Balance);
    void del_info();
    void Account_info();
    void Deposite();
    void Balance_inquery();
    void Withdraw();
    void Make_tranjection();
    void Close_an_account();
};

class Tranjection:public Bank_System
{
public:
//    void Deposite();
//    void Balance_inquery();
//    void Withdraw();
//    void Make_tranjection();
    //  void Account_info();
};

Bank_System::Bank_System()
{
    name=new char[15];
    Address=new char[25];
    password ="";
    Balance=0;
    Account_num=0;
}

Bank_System::Bank_System(char *m_name,char *m_Address,string m_password,int m_Account_num,int m_Balance)
{
    strcpy(name,m_name);
    strcpy(Address,m_Address);
    swap(password,m_password);
    Account_num=m_Account_num;
    Balance=m_Balance;
}


void Bank_System::show_info(char *m_name,char *m_Address,string m_password,int m_Account_num,int m_Balance)
{
    system("cls");
    cout<<"\n\n\n\t   HERE IS YOUR INFORMATION\n\n";

    cout<<"\tName: "<<name<<endl;
    cout<<"\tAddress: "<<Address<<endl;
    cout<<"\tPassword: "<<password<<endl;
    cout<<"\tAccount Number: "<<Account_num;
    cout<<"\tBalance: "<<Balance<<endl;
    getch();
}

void Bank_System::show_info()
{
    system("cls");
    cout<<"Here is your Information\n\n"<<endl;;
    cout<<"\tName: "<<name<<endl;
    cout<<"\tAddress: "<<Address<<endl;
    cout<<"\tAccount Number: "<<get_account_num()<<endl;
    cout<<"\tYour Balance: "<<Balance<<endl;
    getch();
    system("cls");
}

string get_password()
{
    string password;
    char ch;
    cout << "Enter pass: ";
    ch = _getch();
    while(ch != 13)
    {
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    return password;
}

int Choice()
{
    int n;
    cout<<"Main Menu:"<<endl;
    cout<<"\t\t1. New Account"<<endl;
    cout<<"\t\t2. View An Account"<<endl;
    cout<<"\t\t3. Make An Tranjection"<<endl;
    cout<<"\t\t4. Close An Account"<<endl;
    cout<<"\t\t0. Exit"<<endl<<endl;
    cout<<"\t\tSelect Your Option(0-4): ";
    cin>>n;
    system("cls");
    return n;
}

int A_choice()
{
    int n;
    system("cls");
    cout<<"\n\n\t1. View All Info"<<endl;
    cout<<"\n\n\t2. Tranjection"<<endl;
    cout<<"\n\n\t3. Close Account"<<endl;
    cout<<"\n\n\t0. EXIT"<<endl;
    cin>>n;
    system("cls");
    getch();
    return n;
}

int Tranjection_choice()
{
    int n;
    system("cls");
    cout<<"\n\n\t1. Deposite"<<endl;
    cout<<"\n\n\t2. Balance_inquery"<<endl;
    cout<<"\n\n\t3. Withdraw"<<endl;
    cout<<"\n\n\t0. EXIT"<<endl;
    cin>>n;
    return n;
}

int get_account_num();
void Loading();
void T_Time();
//void Make_tranjection();
//void Account_info();
//void Close_an_account();

int main()
{
    Bank_System x;
    int flag=0,n;
    cout<<endl<<endl<<"##========:....WELCOME TO BANK MANAGEMNET SYSTEM....:========##";

    cout<<endl<<endl<<endl;
    while(1)
    {
        n=Choice();
        system("CLS");
        switch(n)
        {
        case 0:
            flag=1;
            break;
        case 1:
            x.New_account();
            break;
        case 2:
            x.View_account();
            break;
        case 3:
            x.Make_tranjection();
            break;
        case 4:
            x.Close_an_account();
        default:
            cout<<"YOU HAVE TO PRESS BETWEEN(0-4)"<<endl;
        }
        if(flag==1)
            break;
    }
}


void Bank_System::View_account()
{
    int i,n_of_list,j,z,y;
    string Pass,chk_password;
    int A_number;
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\tEnter Your Account Number: ";
    cin>>A_number;

    swap(chk_password,password);
    if(A_number==Account_num)
    {
        cout<<"\t\t";
        Pass=get_password();
        if(chk_password==Pass)
        {
            system("CLS");
            Loading();
            Account_info();
        }
        else
        {
            system("CLS");
            cout<<"\a Sorry Your Password is Incorrect Try Again"<<endl;
        }
    }
    if(A_number!=Account_num)
    {
        cout<<'\a'<<endl;
        cout<<"Invalid Account Number"<<endl;
    }
}

void Bank_System::New_account()
{
    int n,flag=1,m,z,y,k,i;
    cout<<"\n\n\t\tNEW ACCOUNT ENTRY FORM"<<endl<<endl;
    cout<<"Name: ";
    cin>>name;
    cout<<"Address: ";
    cin>>Address;
    password=get_password();
    cout<<endl;
    cout<<"Amount of Balance: ";
    cin>>Balance;
    cout<<"Account Number: ";
    cin>>Account_num;
    system("CLS");
    Loading();
    cout<<"\n\n        Your New Account Is Successfully Created      \n\n\nPress Enter"<<endl<<endl<<endl;
    getch();
    show_info();
}

void Bank_System::Deposite()
{
    T_Time();
    int ac_number,money,u_acc_number,u_money;
    cout<<"Enter Your Account Number: ";
    cin>>u_acc_number;
    ac_number=get_account_num();
    money=get_balance();
    if(ac_number==u_acc_number)
    {
        cout<<"Amount Of Money: ";
        cin>>u_money;
        Balance+=u_money;
        Loading();
        cout<<"Record Updated"<<endl;
    }
    else
        cout<<"Wrong account Number"<<endl;
    cout<<endl<<endl<<"Press Enter To Return tranjection Menu"<<endl;
    getch();
}

void Bank_System::Withdraw()
{
    T_Time();
    int ac_number,money,u_acc_number,u_money;
    cout<<"Enter Your Account Number: ";
    cin>>u_acc_number;
    ac_number=get_account_num();
    money=get_balance();
    if(ac_number==u_acc_number)
    {
        cout<<"Amount Of Money: ";
        cin>>u_money;
        if(u_money<Balance)
            {Balance-=u_money;
            Loading();
            cout<<"Record Updated"<<endl;}
        else
            cout<<"Sorry You Do Not Have Sufficient Balance To Make This Tranjection";
    }
    else
        cout<<"Wrong account Number"<<endl;
    cout<<endl<<endl<<"Press Enter To Return tranjection Menu"<<endl;
    getch();
}

void Bank_System::Make_tranjection()
{
    int n,flag=false,acc;
    cout<<"\t\tEnter Your Account Number: ";
    cin>>acc;
    if(Account_num==acc)
    {
        while(1)
        {
            n=Tranjection_choice();
            system("CLS");
            switch(n)
            {
            case 0:
                flag=1;
                break;
            case 1:
                Deposite();
                break;
            case 2:
                show_info();
                break;
            case 3:
                Withdraw();
                break;

            default:
                cout<<"YOU HAVE TO PRESS BETWEEN(0-3)"<<endl;
            }
            if(flag==1)
                break;
        }
    }
    else
        cout<<"Wrong Account Number";
}



int get_account_num()
{
    srand((unsigned)time(0));

    return  rand()%10000;
}

void Loading()
{
    double t;
    cout << "Loading ";
    for (int i=0; i<=3; i++ )
    {
        cout <<".";
        for (t=0; t<=100000000; t++);
    }
}

void T_Time()
{
    time_t t;
    struct tm *now;
    char *p;
    int a, b, c,d,e;
    int nChoice=1;
    time(&t);
    now=localtime(&t);
    a=now->tm_mday;
    b=now->tm_mon+1;
    c=now->tm_year+1900;
    d=now->tm_hour;
    e=now->tm_min;
    if(d>12)
        d=d-12;
    cout<<"\t"<<"Date:"<<a<<"-"<<b<<"-"<<c;
    cout<<"\t\t\t\t\tTIME: "<<d<<":"<<e<<endl<<endl<<endl;
}

void Bank_System::Account_info()
{
    int n,flag=false;
    while(1)
    {
        n=A_choice();
        switch(n)
        {
        case 1:
            show_info();
            break;
        case 2:
            Make_tranjection();
            break;
        case 3:
            Close_an_account();
            break;
        case 0:
            flag=true;
            break;
        default:
            cout<<"YOU HAVE TO PRESS BETWEEN(0-3)"<<endl;
            break;
        }
        if(flag==1)
            break;
    }
}

void Bank_System::Close_an_account()
{
    name='\0';
    free(name);
    Address='\0';
    free(Address);
    password ="Empty";
//    DeleteObject(password);
    Balance=0;
//   free(Balance);
    Account_num=0;
//    free(Account_num);
    Loading();
    cout<<"Your Account Has Been Deleted"<<endl;
    getch();
}

bool operator ==(string &s,string &t)
{
    bool flag=true;
    int n,n1;
    n=s.size();
    n1=t.size();
    if(n!=n1) flag=false;
    else
    {
        for(int i=0; s[i]!='\0'; i++)
        {
            if(s[i]!=t[i])
            {
                flag=false;
                break;
            }
        }
    }
    return flag;
}
