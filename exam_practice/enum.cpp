#include <iostream>

using namespace std;

enum color {red, green = 100, blue};

int main(){
    cout << red << endl;
    cout << green << endl;
    cout << blue << endl;
    return 0;
}