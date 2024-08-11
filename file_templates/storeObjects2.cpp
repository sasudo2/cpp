//program to read and wright in already existing file
// need to learn serialization and deserialization
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
    while(file.peek() != EOF){
        cout << "item" << endl;
        reads.deserialize(file);
        reads.writedata();
    }

    // append new objects
    file.clear();
    Inventory write;
    write.readdata();
    write.serialize(file);

    // Reset the file pointer to the beginning for reading
    file.clear(); // Clear EOF flag
    file.seekg(0, ios::beg);
    cout << "After new Object has been appended" << endl;
    //Displaying already existing data
    while(file.peek() != EOF){
        cout << "item" << endl;
        reads.deserialize(file);
        reads.writedata();
    }

    //changing currently exsting object
    // int i;
    // cout << "Enter the code of item to be changed: ";
    // cin >> i;
    // file.clear();
    // cout << endl << i << endl;
    // file.seekp(0, ios::beg);
    // file.seekg(0, ios::beg);
    // cout << file.tellp() << endl;
    // cout << file.tellg() << endl;
    // while(file.peek() != EOF){
    //     streampos pos = file.tellg();
    //     reads.deserialize(file);
    //     if(reads.same_as(i)){
    //         file.clear();
    //         write.readdata();
    //         file.seekp(pos, ios::beg);
    //         file.seekg(pos, ios::beg);
    //         cout << "this the postition of pointer" << pos << endl;
    //         write.serialize(file);
    //         break;
           
    //     }
    // }
    //  // Reset the file pointer to the beginning for reading
    // file.clear(); // Clear EOF flag
    // file.seekg(0, ios::beg);
    // cout << "After new Object has been appended" << endl;
    // //Displaying already existing data
    // while(file.peek() != EOF){
    //     cout << "item" << endl;
    //     reads.deserialize(file);
    //     reads.writedata();
    // }

    int i;
    cout << "Enter the code of item to be changed: ";
    cin >> i;
    file.clear();
    file.seekg(0, ios::beg);
    streampos pos;
    bool found = false;

    while (file.peek() != EOF) {
        pos = file.tellg();
        reads.deserialize(file);
        if (reads.same_as(i)) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Object found at position: " << pos << endl;
        file.clear(); // Clear any error flags before seeking
        file.seekp(pos); // Use seekp to set the write position
        write.readdata();
        write.serialize(file);
        cout << "Object updated successfully." << endl;
    } else {
        cout << "Object with code " << i << " not found." << endl;
    }

    // Reset the file pointer to the beginning for reading
    file.clear(); // Clear EOF flag
    file.seekg(0, ios::beg);
    cout << "After object has been updated" << endl;
    // Displaying already existing data
    while (file.peek() != EOF) {
        cout << "item" << endl;
        reads.deserialize(file);
        reads.writedata();
    }

    file.close();
    return 0;
}