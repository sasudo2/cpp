#include <iostream>

using namespace std;

class BC{
    public:
    int b;
    void show(){
        cout << "b = " << b << endl;
    }
};

class DC: public BC {
    public:
    int d;
    void show(){
        cout << "b = " << b << endl << "d  = " << d << endl;
    }
};

int main(){
    BC *bptr;
    BC base;
    bptr = &base;
    bptr->b = 100;
    cout << "bptr pointer to base object " << endl;
    bptr->show();

    DC derived;
    bptr = &derived;
    bptr->b = 200;

    cout << "bptr now points to derived object " << endl;
    bptr->show();

    DC *dptr;
    dptr = &derived;
    dptr->d = 300;
    cout << "dptr is derived type ptr" << endl;
    dptr->show();
    cout << "using ((DC *)bptr) \n";
    ((DC *)bptr)->d = 400;
    ((DC *)bptr)->show();
    return 0;
}