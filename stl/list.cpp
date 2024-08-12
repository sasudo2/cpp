#include <iostream>
#include <list>

using namespace std;

void display(list<int> &l){
    cout << "Displaying the contents: ";
    list<int> :: iterator p;
    for(p = l.begin(); p != l.end(); p++){
        cout << *p << ", ";
    }
    cout << endl;
}

int main(){
    list<int> l;
    cout << "Enter 5 dig  its: ";
    int x;
    for(int i = 0; i < 5; i++){
        cin >> x;
        l.push_back(x);
    }

    cout << endl;
    display(l);

    l.push_front(100);
    l.push_back(100);


    l.pop_front();

    cout << "Now list becomes" << endl;
    display(l);

    list<int> b;
    b = l;
    l.merge(b);
    cout << "Merge unsorted list" << endl;
    display(l);

    l.sort();
    cout << "sorted list" << endl;
    display(l);

    l.reverse();
    cout << "Reversed list" << endl;
    display(l);

    return 0;
}