#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
    string a;
    string b;
    cout << "Enter a String: ";
    getline(cin, a);
    cout << a;
    ofstream ofile;
    ofile.open("output.txt");
    for(int i = 0; i < a.length(); i++)
    {
        if(i > 0 && a[i - 1] == ' ')
        {
            if(a[i] == ' ')
            {
                continue;
            }
            else{
                ofile << a[i];
            }
        }
        else{
            ofile << a[i];
        }
        
    }
    ofile.close();
    return 0;
}