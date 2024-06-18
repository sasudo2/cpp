#include <iostream>

using namespace std;

class student{
    protected:
    int roll_number;
    public:
    void get_number(int);
    void put_number();
};

void student::get_number(int i){
    roll_number = i;
}
void student::put_number(){
    cout<< "roll: " << roll_number << endl;
}

class test:public student{
    protected:
    float sub1;
    float sub2;
    public:
    void get_marks(float, float);
    void put_marks();
};

void test::get_marks(float a, float b){
    sub1 = a;
    sub2 = b;
}

void test::put_marks(){
    cout << "sub1: "<<sub1<<endl;
    cout << "sub2: "<< sub2 << endl;
}

class result:public test{
    float total;
    public:
    void display();
};

void result::display(){
    total = sub1 + sub2;
    put_number();
    put_marks();
    cout << "Total marks = " << total << endl;
}

int main(){
    result student1;
    student1.get_number(11);
    student1.get_marks(45, 78);

    student1.display();
    return 0;
}