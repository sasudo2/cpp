#include <iostream>

using namespace std;

class item{
    int code;
    float price;
    public:
    void getitem(int a, float b){
        code = a;
        price = b;
    }
    void show(){
        cout << "code: " << code <<endl;
        cout << "price: " << price << endl;
    }
};

int main(){
    item *p = new item[2];
    item *d = p;
    int a;
    float b;
    for(int i = 0; i < 2; i++){
        cout << "enter the code and price of item: ";
        cin >> a >> b;
        p->getitem(a, b);
        p++;
    }
    for(int i = 0; i < 2; i++){
        d->show();
        d++;
    }
    return 0;
 }