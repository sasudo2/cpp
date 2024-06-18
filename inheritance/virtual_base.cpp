#include <iostream>

using namespace std;

class student{
    protected:
    int roll_number;
    public:
    void get_number(int a){
        roll_number = a;
    }
    void put_number(){
        cout << "Roll No: " << roll_number <<endl;
    }
};

class test:virtual public student{
    protected:
    float part1, part2;
    public:
    void get_marks(float x, float y){
        part1 = x;
        part2 = y;
    }
    void put_marks(void){
        cout << "marks obtained: "<< endl
        << "part1 = " << part1 << endl <<
        "part2 = " << part2 << endl;
    }
};

class sports: public virtual student
{
    protected:
    float score;
    public:
    void get_score(float s){
        score = s;
    }
    void put_score(){
        cout << "Sports wt: " << score << endl << endl;
    }
};

class result: public test, public sports{
    float total;
    public:
    void display();
};

void result::display(void)
{
    total = part1 + part2 + score;
    put_number();
    put_marks();
    put_score();
    cout << "Total Score: "<< total << endl;
}

int main(){
    result student1;
    student1.get_number(678);
    student1.get_marks(30.5, 25.5);
    student1.get_score(7.0);
    student1.display();
    return 0;
}