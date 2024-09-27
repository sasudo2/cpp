#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Student{
    private:
    char name[40];
    int registration;
    char program[40];
    double contact;
    char address[40];
    public:
    Student(){
        cout << "Enter the Details: " << endl;
        cout << "Registraion No.: " ;
        cin >> registration;
        cout << "Name : " ;
        cin >> name;
        cout << "Program : " ;
        cin >> program;
        cout << "Contact : ";
        cin >> contact;
        cout << "address : " ;
        cin >> address;
        cout << endl;
    }
    void store(){
        fstream iofile;
        iofile.open("iofile.txt", ios::app);
        iofile << registration << endl;
        iofile << name << endl;
        iofile << program << endl;
        iofile << contact << endl;
        iofile << address << endl;
        iofile.close();
    }
    void display(){
        cout << "Registraion No.: " << registration << endl;
        cout << "Name : " << name << endl;
        cout << "Program : " << program << endl;
        cout << "Contact : " << contact << endl;
        cout << "address : " << address << endl << endl;
    }
};

int main(){
    int n = 0;
    cout << "Enter the number of students: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        Student s;
        s.store();
    } 

    int r;
    cout << "Enter the registration no. of student: " ;
    cin >> r;
    int temp;
    fstream ifile("iofile.txt", ios::in);
    ifile.seekg(0, ios::beg);
    while(ifile >> temp){
        char name[40];
        char program[40];
        double contact;
        char address[40];
        ifile >> name;
        ifile >> program;
        ifile >> contact;
        ifile >> address;
        if(r == temp){
            cout << "Found!!" << endl;
            cout << "Registraion No.: " << r << endl;
            cout << "Name : " << name << endl;
            cout << "Program : " << program << endl;
            cout << "Contact : " << contact << endl;
            cout << "address : " << address << endl << endl;
            break;
        }
    }
    ifile.close();
    return 0;
}