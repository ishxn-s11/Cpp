//Login Form Implementation
#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;
//Defining Class
class form{
    string username,password,email;
    string search_uname,search_pword,search_email;
    fstream f;
    public:
        void register_user();
        void login();
        void forget_password();

}obj;
void form::register_user(){
    cout<<"\nEnter Your Username:";
    getline(cin,username);
    cout<<"\nEnter Your Email:";
    getline(cin,email);
    cout<<"\nEnter Your Password:";
    getline(cin,password);
    f.open("D:/C++/Projects/userinfo.txt",ios::out|ios::app);
    f<<username<<":"<<email<<":"<<password<<endl;
    f.close();
    Sleep(2000);
    cout<<"\nRegistration Successful!"<<endl;
}
void form::login(){
    cout<<"\nEnter Your Username :";
    getline(cin,search_uname);
    cout<<"\nEnter Your Password :";
    getline(cin,search_pword);
    f.open("D:/C++/Projects/userinfo.txt",ios::in);
    getline(f,username,':');
    getline(f,email,':');
    getline(f,password,'\n');
    while(!f.eof()){
        if(username==search_uname && password==search_pword){
            cout<<"\nLogin Successful!"<<endl;
            cout<<"\nWelcome "<<username<<"!"<<endl;
            cout<<"\nEmail: "<<email<<endl;
            f.close();
            Sleep(2000);
            return;
        }
        else cout<<"\nInvalid Username Or Password!"<<endl;
        getline(f,username,':');
        getline(f,email,':');
        getline(f,password,'\n');
        Sleep(2000);
    }
    f.close();    
}
void form::forget_password(){
    cout<<"\nEnter Your Username:";
    getline(cin,search_uname);
    cout<<"\nEnter Your Email:";
    getline(cin,search_email);
    f.open("D:/C++/Projects/userinfo.txt",ios::in);
    getline(f,username,':');
    getline(f,email,':');
    getline(f,password,'\n');
    while(!f.eof()){
        if(username==search_uname && email==search_email){
            cout<<"\nYour Password Is: "<<password<<endl;
            f.close();
            Sleep(2000);
            return;
        }
        else cout<<"\nInvalid Username Or Email!"<<endl;
        getline(f,username,':');
        getline(f,email,':');
        getline(f,password,'\n');
        Sleep(2000);
    }
}
int main(){
    bool exit=false;
    while(!exit){
    char ch;
    cout<<endl<<"1.Login"<<endl;
    cout<<"2.Register"<<endl;
    cout<<"3.Forget Password"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice:";
    cin>>ch;
        switch(ch){
            case '1': 
                system("cls");
                cout<<"Login Form"<<endl;
                Sleep(2000);
                obj.login();
                break;
            case '2': 
                system("cls");
                cout<<"Register Form"<<endl;
                Sleep(2000);
                obj.register_user();
                break;
            case '3': 
                system("cls");
                cout<<"Forget Password Form"<<endl;
                Sleep(2000);
                obj.forget_password();
                break;
            case '4': 
                system("cls");
                cout<<"Exiting..."<<endl;
                Sleep(2000);
                exit=true;
                break;
            default: 
                system("cls"); 
                cout<<"Invalid Choice!"<<endl;
                Sleep(2000);
                break;
        }
    }
    return 0;
}