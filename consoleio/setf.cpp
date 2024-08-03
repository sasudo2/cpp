#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cout.width(5);
    cout.fill('*');
    cout << "VALUE";

    cout.width(20);
    cout << "SQRT of VALUE" << endl;

    cout.setf(ios::showpos);
    cout.fill('.');
    cout.precision(5);
    cout.setf(ios::showpoint);

    for(int i = 0; i < 11; i++){
        cout.width(5);
        cout.setf(ios::internal, ios::adjustfield);
        cout << i;
        cout.width(20);
        cout.setf(ios::right, ios::adjustfield);
        cout << sqrt(i) << endl;
    }

    cout.setf(ios::scientific, ios::floatfield);
    cout << "SQRT(100) = " << sqrt(100);
    return 0;
}