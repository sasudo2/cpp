#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
    ofstream ofile;
    ofile.open("country");
    
    ofile << "Nepal \n";
    ofile << "India\n";
    ofile << "China\n";

    ofile.close();
    ofile.open("capital");

    ofile << "Kathmandu\n";
    ofile << "New Delhi\n";
    ofile << "Bejing\n";

    ofile.close();

    ifstream ifile;
    ifile.open("country");
    string country;
    while(ifile >> country){
        cout << country << endl;
    }
    cout << endl;
    ifile.close();

    ifile.open("capital");
    string capital;
    while(ifile >> capital){
        cout << capital << endl;
    }

    cout << endl;
    return 0;
}