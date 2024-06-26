#include <iostream>

using namespace std;

class invert1;
class invert2;

class invert1{
    private:
    int code;
    int items;
    float price;
    public:
    invert1(){
        code = items = price = 0;
    }
    invert1(int a, int b, float c){
        code = a;
        items = b;
        price = c;
    }
    invert1(invert2 &a);

    int getcode(){return code;}
    int getitems(){return items;}
    int getprice(){return price;}
    operator float(){return (items*price);}
    void display(){
        cout << endl << code << endl;
        cout << items << endl;
        cout << price << endl;
    }
};

class invert2{
    private:
    int code;
    float value;
    public:
    invert2(){
        code = 0;
        value = 0;
    }
    invert2(int a, float b){
        code = a;
        value = b;
    }
    invert2(invert1 &);

    int getcode(){
        return code;
    }
    int getvalue(){
        return value;
    }

    void display(){
        cout << endl << code << endl;
        cout << value << endl;
    }

};

invert1::invert1(invert2 &a){
        code = a.getcode();
        items = 0;
        price = a.getvalue();
    }

invert2::invert2(invert1 &a){
        code = a.getcode();
        value = a.getitems() * a.getprice();
    }

int main(){
    invert1 i1(1, 2, float(12.78));
    float x = i1;
    invert2 t2(i1);
    i1.display();
    t2.display();
    cout << endl << x << endl;
    return 0;
}