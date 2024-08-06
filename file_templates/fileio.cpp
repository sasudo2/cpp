#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
    ofstream outfile("out");
    string hello;
    cout << "enter some string: ";
    getline(cin, hello);
    outfile << hello;
    outfile.close();
    ifstream infile("out");
    string bye;
    getline(infile, bye);
    cout << bye;
    infile.close();
    return 0;
}