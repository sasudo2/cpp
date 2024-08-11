#include <iostream>

using namespace std;
double divide(double i, double j)
{
    try{
        if(j == 0)
        {
            throw 0;
        }
        return i/j;
    }
    catch(int)
    {
        throw;
    }
}

int main(){
    try{
    double i, j;
    cout << "Enter the number to be divided: ";
    cin >> i;
    cout << "Enter the divider: ";
    cin >> j;
    cout << "answer: " << divide(i, j);
    return 0;  
    }
    catch(int){
        cerr << "divider cannot be zero" << endl;
    }
}