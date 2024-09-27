#include <iostream>
#include <vector>

using namespace std;
template <class t>
void sort(vector<t> &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v.size(); j++){
            if(v[i] > v[j]){
                t temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

template <class t>
void display(vector<t> &v){
    cout << "vector: ";
    for(int i = 0; i <v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int> v;
    int x[5] = {4, 5, 32, 3, 6};
    for(int i = 0; i < 5; i++){
        v.push_back(x[i]);
    }
    cout << "original vector" << endl;
    display<int>(v);
    sort<int>(v);
    cout << "after sorting" << endl;
    display<int>(v);   
}