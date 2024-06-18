#include <iostream>

using namespace std;

class space{
    private:
    int x;
    int y;
    int z;
    public:
    space(){
        x = y = z = 0;
    }
    space(int a, int b, int c){
        x = a;
        y = b;
        z = c;
    }
    void operator - ();
    void display(){
        cout << x << " " << y << " " <<z;
    }

};

void space::operator -(){
    x = -x;
    y = -y;
    z = -z;
}

int main(){
    space a(1, 2, 3);
    -a;
    a.display();
    return 0;
}