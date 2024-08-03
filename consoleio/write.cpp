#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string string1 = "C++ ";
    string string2 = "programming";
    int m = string1.length();
    int n  = string2.length();

    for(int i = 0; i < n; i++)
    {
        cout.write(string2.c_str(), i);
        cout << "\n";
    }

    for(int i = n; i > 0; i--){
        cout.write(string2.c_str(), i);
        cout << endl;
    }

    cout.write(string1.c_str(), m).write(string2.c_str(), n);
    cout << endl;

    cout.write(string1.c_str(), 10);

    return 0;
}