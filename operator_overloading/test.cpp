#include <iostream>

using namespace std;

class c1
{
    
    public:
    int a;
    char b;
    c1(int a, char b): a(a), b(b){}

    c1()
    {
        a = 0;
        b = 0;
    }

    void display()
    {
        cout << a << " " << b << endl;
    }

    // operator c2(){
    //     c2 x;
    //     x.ac = a;
    //     x.cb = b;
    //     return x;
    // }
};

class c2
{
    public:
    int ac;
    int cb;
    c2()
    {
        ac = 0;
        cb = 0;
    }
    c2(c1 x)
    {
        ac = x.a;
        cb = x.b;
    }

    c2(c2& x)
    {
        ac = x.ac;
        cb = x.cb;
    }
    operator c1(){
        c1 x;
        x.a = ac;
        x.b = cb;
        return x;
    }
    void display()
    {
        cout << ac << " " << cb << endl;
    }
};

int main()
{
    c1 a(1, 'c'), d;
    a.display();
    c2 b, c;
    b = a;
    b.display();
    c = b;
    c.display();
    a = c1(b);
    a.display();
    d = b;
    d.display();
    return 0;
}