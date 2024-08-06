#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    float height[4] = {123.24, 324.00, 213.34, 123.33};

    ofstream ofile("height");

    ofile.write((char *) & height, sizeof(height));

    ofile.close();

    for(int i = 0 ; i < 4 ; i++)
    height[i] = 0;

    ifstream ifile("height");

    ifile.read((char*) & height, sizeof(height));

    for(int i = 0; i < 4; i++){
        cout << setw(10) << fixed << setprecision(2) << setiosflags(ios::showpoint) << setiosflags(ios::left) << height[i];
    }
    return 0;
}