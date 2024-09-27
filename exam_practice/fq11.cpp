#include <iostream>
#include <fstream>

using namespace std;

class Book{
    private:
    char name[40];
    int id;
    int quantity;
    char dop[15];
    public:
    void new_book(){
        cout << "Enter the details of book." << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Book Id.: ";
        cin >> id;
        cout << "No. of Books: ";
        cin >> quantity;
        cout << "Date of purchase: ";
        cin >> dop;
        cout << endl;
    }

    void display(){
        cout << "Details of book." << endl;
        cout << "Name: " << name << endl;
        cout << "Book Id.: " << id << endl;
        cout << "No. of Books: " << quantity << endl;
        cout << "Date of Purchase: " << dop << endl;
    }

    void save(fstream & file){
        file << name << endl;
        file << id << endl;
        file << quantity << endl;
        file << dop << endl;
    }

    void retrive(fstream & file){
        file >> name;
        file >> id;
        file >> quantity;
        file >> dop;
    }

    bool is_same(int i){
        if(id == i){
            return true;
        }
        return false;
    }

    
};

int main(){
    Book b;
    int x;
    cout << "enter the number of book: ";
    cin >> x;
    fstream iofile;
    iofile.open("iofile.txt", ios::out);
    for(int i = 0; i < x; i++){
        b.new_book();
        b.save(iofile);
    }

    iofile.close();
    iofile.open("iofile.txt", ios::in);
    cout << "enter the id of the book you want to search: ";
    cin >> x;
    while(iofile.peek() != EOF){
        b.retrive(iofile);
        if(b.is_same(x)){
            b.display();
            break;
        }
    }
    iofile.close();
    return 0;
}