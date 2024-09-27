#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class student{
    private:
    char name[40];
    int roll;
    double contact;
    float score;
    public:
    void get_data(){
        cout << "Enter the details of the student: " << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Roll No.: " ;
        cin >> roll;
        cout << "Contact No.: ";
        cin >> contact;
        cout << "Score: ";
        cin >> score;
    }
    void display(){
        cout << endl << "Name: " << name << endl;
        cout << "Roll No.: " << roll << endl;
        cout << "Contact No.: " << contact << endl;
        cout << "Score: " << score << endl;
    }
    void store(){
        fstream file;
        file.open("iofile.dat", ios::out|ios::binary);
        file.write((char*) name, sizeof(name));
        file.write((char *) &roll, sizeof(roll));
        file.write((char *) &contact, sizeof(contact));
        file.write((char *) &score, sizeof(score));
        file.close();
    }
    void retrive(){
        fstream file;
        file.open("iofile.dat", ios::binary|ios::in);
        file.read((char *) name, sizeof(name));
        file.read((char *) &roll, sizeof(roll));
        file.read((char *) &contact, sizeof(contact));
        file.read((char *) &score, sizeof(score));
        file.close();
    }
};

int main(){
    student s1, s2;
    s1.get_data();
    s1.store();
    s2.retrive();
    s2.display();
    return 0;

}