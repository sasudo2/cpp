#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v(10);
    v[0]=0;
    v[9] =9;
    for(int i = 1; i <= 8; i++){
        v[i] = 1;
    }
    vector<int> :: iterator ite;
    for(ite = v.begin(); ite != v.end(); ite++){
        cout << *ite << ", ";
    }
    return 0;
}