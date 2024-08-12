#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;
    for(int i = 0; i < 50; i++){
        v.push_back( rand() % 100);
    }
    int f;

    cout << "Enter a number to find: ";
    cin >> f;

    auto it = find(v.begin(), v.end(), f);
    if(it != v.end()){
        cout << "Element found at the index " << distance(v.begin(), it) << endl;

    }
    else {
        cout << "Element not found.";
    }

    cout << endl << endl << "Elements: ";

    for(int i = 0; i < 50; i++){
        cout << v[i] << ", ";
    }
    return 0;

}
