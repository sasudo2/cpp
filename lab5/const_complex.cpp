#include <iostream>

using namespace std;


class Complex{
    private:
    const float real = 12;
    float imag;
    public:
    Complex():imag(0) {}
    Complex(float i):imag(i) {}
    float get_real() const {
        return real;
    }
    float get_imaginary() const {
        return imag;
    }
    void display() const ;

};

void Complex::display() const {
    cout << "number: " << get_real() << " + " 
    << get_imaginary() << "i" << endl;
}

int main(){
    const Complex a(23);
    a.display();
    return 0;
}
