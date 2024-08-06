//program to read and wright in already existing file

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

// class inventory
class Inventory{
    private:
    string item;
    int code;
    float price;
    public:
    void readdata(){
        cout << "Enter Name: "; cin >> item;
        cout << "Enter Code: "; cin >> code;
        cout << "Enter Price: "; cin >> price;
    }
    void writedata(){
        cout << "Name: " << item << endl;
        cout << "Code: " << code << endl;
        cout << "price: " << price << endl << endl;
    }
};

int main(){
    Inventory reads;

    //file object
    fstream file;
    
    //opening an already existing file to perform both input and output in append mode
    file.open("inventory.DAT", ios::in | ios::out | ios::app | ios::binary);
     if (!file) {
        cerr << "File could not be opened!" << endl;
        return 1;
    }

   // Reset the file pointer to the beginning for reading
    file.clear(); // Clear EOF flag
    file.seekg(0, ios::beg);

    //Displaying already existing data
    while(file.read((char*)& reads, sizeof(Inventory))){
        cout << "item" << endl;
        reads.writedata();
    }

    //To Do append new objects
   
    file.close();
    return 0;
}