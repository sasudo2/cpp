#include <iostream>
#include <cmath>

using namespace std;

class Polar{
    float radius;
    float angle;
    public:
    Polar(){radius = angle = 0;}
    Polar(float r, float a){radius = r;
    angle = a;}
    Polar(Polar &a){
        radius = a.radius;
        angle = a.angle;
    }

    Polar operator + (Polar &);
    void display();
};

Polar Polar::operator + (Polar &a){
    Polar temp;
    float x1 = radius * cos(angle);
    float y1 = radius * sin(angle);
    float x2 = a.radius * cos(a.angle);
    float y2 = a.radius * sin(a.angle);
    float x = x1 + x2;
    float y = y1 + y2;
    temp.radius = sqrt(x*x + y*y);
    temp.angle = atan2(y, x);
    return temp;
}

void Polar::display(){
    cout << "(" << radius << ", " << angle << ")" << endl;
}


int main(){
    Polar a(1, 1);
    Polar b(2, 2);
    a.display();
    a = a + b;
    a.display();
    return 0;
}