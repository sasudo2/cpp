#include <iostream>
#include <string.h>

using namespace std;

class staff{
    protected:
    char *codename;
    staff(const char *code){
        codename = new char[strlen(code)];
        strcpy(codename, code);
    }
};
class officer: public staff{
    private:
    int grade;
    public:
    officer(const char *code, int g): staff(code), grade(g){}
    void display(){
        cout << "CodeName: " << codename << endl;
        cout << "Grade: " << grade<< endl;
    }
};
class teacher: public staff{
    private:
    char *subject;
    public:
    teacher(const char*code, const char*sub):staff(code){
        subject = new char[strlen(sub)];
        strcpy(subject, sub);
    }
    void display(){
        cout << "CodeName: " << codename <<endl;
        cout << "Subject PUblication: " << subject <<endl;
    }
};
class typist: public staff{
    private:
    int speed;
    public:
    typist(const char*code , int s): staff(code){
        speed = s;
    }
    void display(){
    cout << "CodeName: " << codename <<endl;
    cout << "Speed: " << speed << "wpm" << endl;
    }
};
class regular: public typist{
    public:
    regular(const char*code, int s): typist(code, s){}

};
class casual: public typist{
    private:
    int dailywage;
    public:
    casual(const char*code, int s, int w): typist(code, s){
        dailywage = w;
    }
    void display(){
        typist::display();
        cout << "DailyWage: " << dailywage <<endl;
    }
};

int main(){
    officer o1("o12", 2);
    regular r1("r1", 80);
    casual c1("c1", 60, 120);
    o1.display();
    r1.display();
    c1.display();
    return 0;
}

