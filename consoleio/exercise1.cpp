#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main(){
    int code[5] = {234, 234, 1234, 532, 211};
    float cost[5] = {234.121, 324.423, 324.32, 111.21, 123.12};
    string name[5] = {"Turbo c++", "Cprimer", "vscode", "dev c++", "code block"};

    cout.precision(2);
    cout << setw(10) << setiosflags(ios::left) << "NAME" << resetiosflags(ios::left) << setw(10) << "CODE" << setw(12) << "COST" << endl;

    for(int i = 0; i < 5; i++){
        cout << setw(10) << setiosflags(ios::left) << name[i] << resetiosflags(ios::left) << setw(10) << code[i]
         << setw(12) << fixed << setprecision(2) << setiosflags(ios::showpoint)  << cost[i] << endl;
    }
    return 0;
}