#include <iostream>
#include <string.h>

using namespace std;

class String{
    private:
    int len;
    char *p;
    public:
    String(){
        len = 0;
        p = 0;
    }
    String(const char *a){
        len = strlen(a);
        p = new char[len + 1];
        strcpy(p, a);
    }
    String(String &a){
        len = a.len;
        p = new char(len+1);
        strcpy(p, a.p);
    }
    ~String(){
        delete p;
    }

    friend String operator + (String &a, String &b){
        String temp;
        temp.len = b.len + a.len;
        temp.p = new char[temp.len + 1];
        strcpy(temp.p, a.p);
        strcat(temp.p, b.p);
        return temp;
    }

    friend bool operator <= (String &a, String&b){
        if(strcmp(a.p, b.p) <= 0){
            return true;
        }
        else{
            return false;
        }
    }

    friend void display(String &a){
        cout << a.p << endl;
    }
};

int main(){
    String s1("New ");
    String s2 = "York";
    String t1, t2 = s1 + s2;
    t1 = s1; 
    display(s1);
    display(s2);
    display(t1);
    display(t2);
    return 0;
}