#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    string input;
    cout << "Enter some string: ";
    getline(cin, input);
    
    fstream file;
    file.open("out", ios::in | ios::out);
    int l = input.length();
    for(int i = 0; i < l; i++){
        file.put(input[i]);
    }
    char c;
    cout << file.tellg() << endl;
    cout << file.tellp() << endl;
    file.seekg(0);
    cout << file.tellg() << endl;
    cout << file.tellp() << endl;
    while(file)
    {
        file.get(c);
        cout << c;
    }
    file.close();
    return 0;
}