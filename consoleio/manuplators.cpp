#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << setw(5) << 'n' << setw(20) << "Inverse of n" << setw(20) << "Sum of terms" << endl;
    float sum = 0;
    for(int i = 1; i < 11; i ++){
        float term = 1.0 /float(i);
        sum = sum + term;
        cout << setw(5) << i << setw(20) << setprecision(5) << setiosflags(ios::scientific) << term <<
        setw(20) << resetiosflags(ios::scientific) << setiosflags(ios::showpoint) << sum << endl;

    }
    return 0;
}