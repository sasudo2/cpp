#include <iostream>

using namespace std;

class Complex{
    float real;
    float imag;
    static int counter;

    public:
    Complex():real(0), imag(0){}
    Complex(float r, float i){
        real = r;
        imag = i;
        counter++;
    }
    Complex( Complex &c){
        real = c.real;
        imag = c.imag;
        counter++;
    }
    static int getCounter(){
        return counter;
    }
    void display(){
        cout << "number: " << real << " + " << imag << "i" << endl;
    }
};

int Complex::counter;

int main(){
    Complex c1(12, 23);
    Complex c3(2, 4);
    Complex c2(c1);

    cout << "Counter: " << c1.getCounter() << endl; 

    return 0;

}