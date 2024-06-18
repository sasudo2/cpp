#include <iostream>

using namespace std;

class FLOAT{
    float a;
    public:
    FLOAT(){
        a = 0;
    }
    FLOAT(float x){
        a = x;
    }
    FLOAT(FLOAT &x){
        a = x.a;
    }

    FLOAT operator + (FLOAT & x){
        return FLOAT(a + x.a);
    }
    FLOAT operator * (FLOAT & x){
        return FLOAT(a * x.a);
    }
    FLOAT operator - (FLOAT & x){
        return FLOAT(a - x.a);
    }
    FLOAT operator / (FLOAT & x){
        return FLOAT(a / x.a);
    }

    friend ostream & operator << (ostream & fout, FLOAT & f){
        fout << f.a << endl;
        return fout;
    }

    friend istream & operator >> (istream & fin, FLOAT & f){
        fin >> f.a;
        return fin;
    }
};

int main(){
    FLOAT a(3.1415);
    FLOAT b;
    cout << a;
    cout << "enter a float: ";
    cin >> b;
    cout << b;
    return 0;

}