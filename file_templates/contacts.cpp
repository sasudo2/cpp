#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
    ifstream ifile;
    ifile.open("contacts.txt");
    string contact;
    string name;
    while(ifile >> name && ifile >> contact)
    {
    }
    ifile.close();
    return 0;
}