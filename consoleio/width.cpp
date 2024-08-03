/*width
precision
fill
setf
unsetf

setw
setpresecion
setfill
setiosflag
unsetiosflag
*/

#include <iostream>

using namespace std;

int main(){
    int item[4] = {1, 2, 42, 54};
    int cost[4] = {10, 30, 23, 80};

    cout.width(5);
    cout << "ITEMS";
    cout.width(8);
    cout <<"COST";
    cout.width(15);
    cout << "TOTAL VALUE"<< endl;
    int sum = 0;

    for(int i = 0; i< 4 ; i++){
        cout.width(5);
        cout << item[i];
        cout.width(8);
        cout << cost[i];
        cout.width(15);
        cout << item[i]*cost[i] << endl;
        sum = sum + item[i]*cost[i];
    }
    cout << "Grand Total: ";
    cout.width(2);
    cout << sum << endl;
    return 0;

}