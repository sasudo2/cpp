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
        char c;
        cout << "Enter Name: "; cin >> item;
        cout << "Enter Code: "; cin >> code;
        cout << "Enter Price: "; cin >> price;
    }
    void writedata(){
        cout << "Name: " << item << endl;
        cout << "Code: " << code << endl;
        cout << "price: " << price << endl << endl;
    }
    void serialize(fstream &file){
        size_t length = item.size();
        file.write((char*) & length, sizeof(length));
        file.write((char*) item.c_str(), length);
        file.write((char*) &code, sizeof(code));
        file.write((char*) &price, sizeof(price));

    }
    void deserialize(fstream &file){
        size_t length;
        file.read((char*) &length, sizeof(length));
        item.resize(length);
        file.read(&item[0], length);
        file.read((char*) &code, sizeof(code));
        file.read((char*) &price, sizeof(price));
    }
    bool same_as(int i){
        if(i == code){
            return true;
        }
        return false;
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
        items[i].serialize(file);
    }

    //reading the data
    Inventory reads;
    file.clear();
    file.seekg(0);
    while(file.peek() != EOF){
        cout << "item" << endl;
        reads.deserialize(file);
        reads.writedata();
    }
    file.close();
    return 0;
}

