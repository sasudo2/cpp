#include <iostream>

using namespace std;

void (*ptr)(int, int);

void add(int a, int b){
    cout << " a + b = " << a + b << endl;
}

void subtract(int a, int b){
    cout << " a - b = " << a - b << endl;
}

int main(){
    int a = 8;
    int b = 5;
    ptr = &add;
    ptr(a, b);
    ptr = &subtract;
    ptr(a, b);
    return 0;
    
}