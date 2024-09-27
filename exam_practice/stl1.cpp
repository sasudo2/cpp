#include <iostream>
#include <vector>

using namespace std;

void display(vector <int> & i){
    cout << "vecotr: ";
    for(int j = 0; j < i.size(); j++){
        cout << i[j] << " ";
    }
    cout << endl;
}


int main(){
    vector<int> i;
    cout << "Initial size of vector: " << i.size() << endl;

    int x;
    cout << "enter five numbers" << endl;
    for(int j = 0; j < 5; j++){
        cin >> x;
        i.push_back(x);
    }

    display(i);
    
    i.push_back(3);

    vector<int>::iterator itr = i.begin();
    i.insert(itr+5, 1, 9);
    cout << "inserting elements" << endl;
    display(i);

    i.erase(i.begin()+3, i.begin()+4);
    cout << "after erasing certain elements: "<< endl;
    display(i);

    return 0;
}