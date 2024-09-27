#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class student{
    private:
    char name[40];
    int roll;
    char address[40];
    int marks;
    public:
    void get_data(){
        cout << "Enter the details of Student" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Roll No.: ";
        cin >> roll;
        cout << "Address: ";
        cin >> address;
        cout << "Marks: ";
        cin >> marks;
        cout << endl;
    }
    void display(){
        cout << "Detail of Student: " << endl;
        cout << "Name: " << name << endl;
        cout << "roll: " << roll << endl;
        cout << "Address: " << address << endl;
        cout << "Marks: " << marks << endl << endl;
    }

    void store(fstream &file){
        file.write((char *) name, sizeof(name));
        file.write((char *) &roll, sizeof(roll));
        file.write((char *) address, sizeof(address));
        file.write((char *) &marks, sizeof(marks));
    }

    void retrieve(fstream &file){
        file.read((char *) name, sizeof(name));
        file.read((char *) &roll, sizeof(roll));
        file.read((char *) address, sizeof(address));
        file.read((char *) &marks, sizeof(marks));
    }
    bool same(int r){
        if(r == roll){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator > (student & s){
        if(marks > s.marks){
            return true;
        }
        else {
            return false;
        }
    }

};

int main(){
    int x;
    student s;
    cout << "enter the number of students: ";
    cin >> x;
    fstream file;
    file.open("iofile.dat", ios::binary|ios::out);
    for(int i = 0; i < x; i++){
        s.get_data();
        s.store(file);
    }
    file.close();

    file.open("iofile.dat", ios::binary|ios::in);
    student* sl = new student[x];
    for(int i = 0; i < x; i++){
        sl[i].retrieve(file);
    }
    for(int i = 0; i < x; i++){
        for(int j = i; j < x; j++){
            if(sl[j]>sl[i]){
                student temp;
                temp = sl[j];
                sl[j] = sl[i];
                sl[i] = temp;
            }
        }
    }
    for(int i = 0; i < x; i++){
        sl[i].display();
    }
    file.close();
    return 0;
}
