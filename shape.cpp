#include <iostream>

using namespace std;

class shape{
    public:
    int a;
    int b;
    void get_data(int x, int y){
        a = x;
        b = y;
    }
    virtual void display_area(){}
};

class rectangle: public shape{
    public:
    void display_area(){
        cout << "Area: " << a*b << endl;
    }
};

class triagle: public shape{
    public:
    void display_area(){
        cout << "Area: " << a*b/2 << endl;
    }
};

int main(){
    shape *s;
    rectangle r1;
    s = &r1;
    cout << "using base pointer to point to derived rectangel object"<< endl;
    s->get_data(2, 4);
    s->display_area();
    triagle t1;
    s = &t1;
    cout << "using base pointer to point to derived triangle object" << endl;
    s->get_data(3, 6);
    s->display_area();
    return 0;
}