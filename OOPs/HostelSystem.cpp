//Hostel Accommodation System
//Importing Libraries
#include<iostream>
#include<fstream> //For File Handling
#include<sstream> //For String Manipulations
#include<windows.h> //For Sleep Function
using namespace std;

//Defining Class
class Hostel{
    private:
    //Statically Defined Members
        string name;
        int rent,bed;
    public:
        //Constructor
        Hostel(string name,int rent,int bed){ //Parameterized Constructor
            this->name=name;
            this->rent=rent;
            this->bed=bed;
        }
        //Getter Functions
        string get_name(){return name;}
        int get_rent(){return rent;}
        int get_bed(){return bed;}
        void reserve_room(){
            //For Reading Data From File
            ifstream in("D:/C++/Projects/hostelinfo.txt");
            //For Storing Data Into File
            ofstream out("D:/C++/Projects/hostel_temp.txt");
            string ptr;
            while(getline(in,ptr)){
                int pos=ptr.find("ABC Hostel"); //Searching For Hostel Name In File
                if(pos!=string::npos){ //Exists
                    int bed_count=bed-1; //Decreasing Bed Count By 1
                    bed=bed_count; //Updating Bed Count
                    stringstream ss;
                    ss<<bed_count; //Converting Bed Count To String
                    string strbed=ss.str();
                    int bedpos=ptr.find_last_of(":"); //Finding Position Of Last Colon
                    ptr.replace(bedpos+1,string::npos,strbed);
                }
                out<<ptr<<endl; //Writing Updated Data To Temp File
            }
            out.close();
            in.close();
            remove("D:/C++/Projects/hostelinfo.txt"); //Removing Old File
            rename("D:/C++/Projects/hostel_temp.txt","D:/C++/Projects/hostelinfo.txt"); //Renaming Temp File To Original File
            cout<<"\tRoom Reserved Successfully!"<<endl;
        }
};

class Student{
    private:
    //Dynamically Defined Members
        string name,id,address;
    public:
        //Constructor
        Student():name(""),id(""),address(""){} //Default Constructor
        //Setter And Getter Functions
        void set_name(string name){this->name=name;}
        void set_id(string id){this->id=id;}
        void set_address(string address){this->address=address;}
        string get_name(){return name;}
        string get_id(){return id;}
        string get_address(){return address;}
};

//Main Function 
int main(){
    //Creating Hostel Object
    Hostel h("ABC Hostel",5000,2);
    ofstream out("D:/C++/Projects/hostelinfo.txt");
    out<<"\t"<<h.get_name()<<":"<<h.get_rent()<<":"<<h.get_bed()<<":"<<endl<<endl;
    cout<<"Data Saved"<<endl;
    out.close();
    Student s;
    bool exit=false;
    while(!exit){
        system("cls");
        int val;
        cout<<"Hostel Accommodation System"<<endl;
        cout<<"\t1.Reserve A Room"<<endl;
        cout<<"\t2.Exit"<<endl;
        cout<<"Enter Your Choice:";
        cin>>val;
        switch(val){
            case 1:{
                system("cls");
                string name,id,address;
                cout<<"\tAllocate A Room"<<endl;
                cout<<"Enter Name Of Student:";
                cin>>name;
                s.set_name(name);
                cout<<"Enter ID Of Student:";
                cin>>id;
                s.set_id(id);
                cout<<"Enter Address Of Student:";
                cin>>address;
                s.set_address(address);
                if(h.get_bed()>0) h.reserve_room(); //Checking Bed Availability
                else if(h.get_bed()==0){
                    cout<<"\tNo Beds Available!"<<endl;
                    Sleep(3000);
                    break;
                }
                ofstream out("D:/C++/Projects/studentinfo.txt",ios::app);
                out<<"\t"<<s.get_name()<<":"<<s.get_id()<<":"<<s.get_address()<<endl<<endl;
                out.close();
                cout<<"Student Information Saved Successfully!"<<endl;
                Sleep(3000);
                break;
            }
            case 2:{
                system("cls");
                exit=true;
                cout<<"\tExiting..."<<endl;
                Sleep(3000);
                break;
            }
        }
    }
}