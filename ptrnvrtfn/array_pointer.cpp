#include <iostream>
#include <conio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int main(){
    int i = 0;
    char *ptr[10] = {
        "books",
        "television",
        "computer",
        "sports"
    };
    char str[25];
    cout << "\n\n\nEnter your favorite leisure pursuit: ";
    cin >> str;
    for(i = 0; i < 4; i++){
        if(!strcmp(str, ptr[i])){// we cannot use *ptr[i]
            cout << "\n\nYour favorite pursuit " << "is availabel here" << endl;
            break;
        }

    }
    if(i==4){
        cout << "\n\nYour favorite " << " not available here" << endl;
    }
    return 0;
}