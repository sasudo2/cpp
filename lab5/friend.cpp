#include <iostream>
#include <cmath>

using namespace std;

class Complex{
    float real;
    float imag;
    public:
    Complex():real(0), imag(0){}
    Complex(float r, float i){
        real = r;
        imag = i;
    }
    Complex( Complex &c){
        real = c.real;
        imag = c.imag;
    }
    void display(){
        cout << "number: " << real << " + " << imag << "i" << endl;
    }
    friend float magnitude(Complex &);
};

float magnitude(Complex &a){
    return sqrt(a.real*a.real + a.imag*a.imag);
}

int main(){
    Complex c1(12, 23);
    cout << "magnitude: " << magnitude(c1) << endl;
    return 0;

}