#include <iostream>

using namespace std;

class Time{
    private:
    int hr;
    int mn;
    int sec;
    public:
    Time():hr(12), mn(0), sec(0){}
    Time(int h, int m, int s){
        hr = s/3600;
        mn = s/60 - hr*60;
        sec = s - mn*60 - hr*3600;

        mn = mn + m - (m/60)*60;
        hr = hr + m/60;
        
        hr = hr + h;
    }
    Time(Time & t){
        hr = t.hr;
        mn = t.mn;
        sec = t.sec;
    }

    void display(){
        cout << "hour: " << hr << endl
        << "minute: " << mn << endl
        << "second: " << sec << endl << endl;
    }
};

int main(){
    Time t1(1, 23, 45);
    Time t2;
    t2 = t1;
    t1.display();
    t2.display();
    return 0;
}