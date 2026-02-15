//Super Market Billing System
//Importing Libraries
#include<iostream>
#include<fstream> //For File Handling
#include<sstream> //For String Manipulations
#include<windows.h> //For Sleep Function
using namespace std;

//Defining Classes
class Bill{
    private:
    string item;
    int rate,qnt;
    public:
    //Constructor
    Bill():item(""),rate(0),qnt(0){}
    //Setters and Getters
    void set_item(string item_name){
        item=item_name;
    }
    void set_rate(int item_rate){
        rate=item_rate;
    }
    void set_qnt(int item_qnt){
        qnt=item_qnt;
    }
    string get_item(){
        return item;
    }
    int get_rate(){
        return rate;
    }
    int get_qnt(){
        return qnt;
    }

};

//Function to Add Item to Bill
void add_tem(Bill b){
    bool close=false;
    while(!close){
        int ch;
        cout<<"\t1. Add Item"<<endl;
        cout<<"\t2. Close Bill"<<endl;
        cout<<"\tEnter Choice:";
        cin>>ch;
        switch(ch){
            case 1:{
                system("cls");
                string item;
                int rate,qnt;
                cout<<"\tEnter Item Name:";
                cin>>item;
                b.set_item(item);
                cout<<"\tEnter Item Rate:";
                cin>>rate;
                b.set_rate(rate);
                cout<<"\tEnter Item Quantity:";
                cin>>qnt;
                b.set_qnt(qnt);
                //File Name Is out
                ofstream out("C:\\Users\\TRAGI\\Desktop\\VS Code\\C++\\Projects\\Bill.txt",ios::app); //Opening File In Append Mode
                if(!out) cout<<"\t Error: File Can't Open"<<endl;
                else out<<"\t"<<b.get_item()<<":"<<b.get_rate()<<":"<<b.get_qnt()<<endl<<endl;
                out.close();
                cout<<"\tItem Added Successfully!"<<endl;
                Sleep(3000); //Pauses The Program For 2 Seconds
                break;
            }
            case 2:
                system("cls");
                close=true;
                cout<<"\tBill Closed!"<<endl;
                Sleep(1500);
                break;
        }
    }
}

//Function to Display Bill
void display_bill(){
    int count=0;
    bool close=false;
    int ch;
    cout<<"\t1. Add Bill"<<endl;
    cout<<"\t2. Close Session"<<endl;
    cout<<"\tEnter Choice:";
    cin>>ch;
    while(!close){
        system("cls");
        switch(ch){
            case 1:
            {
                string item;
                int qnt;
                cout<<"\tEnter Item:";
                cin>>item;
                cout<<"\tEnter Quantity:";
                cin>>qnt;
                //Reading Data Out From File
                ifstream in("C:\\Users\\TRAGI\\Desktop\\VS Code\\C++\\Projects\\Bill.txt");
                //Writing Data Into File
                ofstream out("C:\\Users\\TRAGI\\Desktop\\VS Code\\C++\\Projects\\Temp_Bill.txt");
                string line;
                bool found=false;
                while(getline(in,line)){
                    stringstream stream_s;
                    stream_s<<line;
                    string item_name;
                    int item_rate,item_qnt;
                    char delimiter; //To Seperate Data
                    stream_s>>item_name>>delimiter>>item_rate>>delimiter>>item_qnt;
                    if(item==item_name){
                        found=true;
                        if(qnt<=item_qnt){
                            cout<<"\tItem | Rate | Quantity | Amount"<<endl;
                            cout<<"\t"<<item_name<<"\t"<<item_rate<<"\t"<<qnt<<"\t"<<item_rate*qnt<<endl;
                            item_qnt-=qnt;
                            count+=item_rate*qnt;
                            out<<"\t"<<item_name<<":"<<item_rate<<":"<<item_qnt<<endl; 
                        }
                        else cout<<"\t"<<item<<"Not In Stock!"<<endl;
                    }
                    else{
                        out<<line<<endl; 
                    }
                }
                if(!found) cout<<"\tItem Not Available!"<<endl;
                out.close();
                in.close();
                //Updating Temp File
                remove("C:\\Users\\TRAGI\\Desktop\\VS Code\\C++\\Projects\\Bill.txt");
                //Destination <--- Source
                rename("C:\\Users\\TRAGI\\Desktop\\VS Code\\C++\\Projects\\Temp_Bill.txt","C:\\Users\\TRAGI\\Desktop\\VS Code\\C++\\Projects\\Bill.txt");
                break;
            }
            case 2:
                close=true;
                cout<<"\tTotal Bill"<<endl;
                break;
        }
        Sleep(3000);        
    }
    system("cls");
    cout<<endl<<endl;
    cout<<"\tTotal Bill:"<<count<<endl<<endl;
    Sleep(3500);
}

//Main Function
int main(){
    Bill b;
    bool exit=false;
    while(!exit){
        system("cls"); //Clears Previous Output
        int val;
        cout<<"\tSuper Market Billing System"<<endl<<endl;
        cout<<"\t1. Add Item"<<endl;
        cout<<"\t2. Print Bill"<<endl;
        cout<<"\t3. Exit"<<endl;
        cout<<"\tEnter Choice:";
        cin>>val;
        switch(val){
            case 1:
                system("cls");
                add_tem(b);
                Sleep(3000);
                break;
            case 2:
                system("cls");
                display_bill();
                Sleep(3000);
                break;
            case 3:
                system("cls");
                exit=true;
                cout<<"\tExiting..."<<endl;
                Sleep(1500);
                break;
        }
    
    }
}