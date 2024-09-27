#include <iostream>

using namespace std;

template <class t>
t power(t x, int p){
    if(p < 0){
        p = -1*p;
    }
    t result = 1;
    for(int i = 0; i < p; i++){
        result *= x;
    }
    return result;
}

int main(){
    float a = 23.44;
    int b = 5;
    float c = power<float>(a, b);
    cout << "a^b = " << c << endl;
    return 0;
}