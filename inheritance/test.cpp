#include <iostream>
#include <string.h>

using namespace std;

class Student{
    char* name;
    int rollNumber;
    protected:
    Student(){
        strcpy(name, "alankey");
    }
    void setNumber(int no){
        rollNumber = no;
    }
    int getRollNumber(){
        return rollNumber;
    }
};

class AnualTest: Student {
    int mark1, mark2;
    public:
    AnualTest(int m1, int m2): mark1(m1), mark2(m2){}
    int getRollNumber(){
        return Student::getRollNumber();
    }
};

int main()
{
    AnualTest test1(92, 85);
    cout<<test1.getRollNumber();
    return 0;
}