#include <iostream>

using namespace std;


class Complex{
    private:
    const float real = 12;
    float imag;
    public:
    Complex():imag(0) {}
    Complex(float i):imag(i) {}
    const float get_real(){
        return real;
    }
    float get_imaginary(){
        return imag;
    }
    const void display();

};

const void Complex::display(){
    cout << "number: " << get_real() << " + " << get_imaginary() << "i" << endl;
}

int main(){
    Complex a(23);
    a.display();
    return 0;
}
