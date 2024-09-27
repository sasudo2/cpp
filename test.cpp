#include <iostream>
#include <iomanip>

using namespace std;

class Time{
    private:
    int hour;
    int minute;
    int sec;
    public:
    Time(){
        hour = 0;
        minute = 0;
        sec = 0;
    }
    Time(int h, int m, int s){
        sec = s % 60;
        minute = m + s/60;
        hour = h + minute/60;
        minute = minute%60;
    }
    Time(Time &t){
        sec = t.sec;
        minute = t.minute;
        hour = t.hour;
    }
    
    void display(){
        cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << sec << endl;
    }
    
    Time operator + (Time &t){
        int s = sec + t.sec;
        int m = minute + t.minute;
        int h = hour + t.hour;
        return Time(h, m, s);
    }
};

int main(){
    Time t1(3, 43, 23);
    Time t2(4, 23, 56);
    Time t3 = t1 + t2;
    t3.display();
    return 0;
}