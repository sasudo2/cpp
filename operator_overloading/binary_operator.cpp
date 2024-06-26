#include <iostream>

using namespace std;

class Complex{
    private:
    int real;
    int imaginary;
    public:
    Complex(){
        real = imaginary = 0;
    }
    Complex(int r, int i){
        real = r;
        imaginary = i;
    }
    Complex operator +(Complex);
    void display(){
        cout<< real <<" + "<< imaginary <<"i"<<endl;
    }
};

Complex Complex::operator + (Complex a){
    Complex t;
    t.real = real + a.real;
    t.imaginary = imaginary + a.imaginary;
    return t;
}

int main(){
    Complex a(12, 13), b(14, 15);
    a = a + b;
    a.display();
    return 0;
    
}