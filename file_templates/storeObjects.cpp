#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

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
    Inventory items[2];
    fstream file;
    file.open("inventory.DAT", ios::in | ios::out | ios::trunc | ios::binary);
    if(!file){
        cerr << "Erroe opening file" << endl;
        return 1;
    }
    //writing data
    for(int i = 0; i < 2; i++)
    {
        items[i].readdata();
        file.write((char *) & items[i], sizeof(items[i]));
    }

    //reading the data
    Inventory reads;
    file.seekg(0);
    while(file.read((char*)& reads, sizeof(reads))){
        cout << "item" << endl;
        
        reads.writedata();
    }
    file.close();
    return 0;
}