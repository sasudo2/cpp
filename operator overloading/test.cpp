#include <iostream>

enum WeekDays{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};

bool operator == (WeekDays & w1, WeekDays & w2){
    if(w1 == sunday && w2 ==  sunday){
        return true;
    }
    else if(w1 == monday && w2 == monday){
        return true;
    }
    else if(w1 == tuesday && w2 == tuesday){
        return true;
    }
    else if(w1 == wednesday && w2 == wednesday){
        return true;
    }
    else if(w1 == wednesday && w2 == wednesday){
        return true;
    }
    else if(w1 == thursday && w2 == thursday){
        return true;
    }
    else if(w1 == friday && w2 == friday){
        return true;
    }
    else if(w1 == saturday && w2 == saturday){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    WeekDays w1 = sunday;
    WeekDays w2 = monday;
    return 0;
}