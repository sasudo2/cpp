#include <iostream>
#include <vector>

using namespace std;

template<class t>
void display(vector<t> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    cout << "Initial size: " << v.size() << endl;

    //inseting values
    int x;
    cout << "Enter five digits: ";
    for(int i = 0; i < 5; i++){
        cin >> x;
        v.push_back(x);
    }
    cout << "Size after adding values: " << v.size() << endl;

    //Displaying content
    cout << "Displaying Contents: ";
    display<int>(v);

    //Add one more value
    v.push_back(33);

    //Inserting elements
    vector<int> :: iterator itr = v.begin();
    itr = itr + 3;
    v.insert(itr, 2, 9);

    //Display the content
    cout << "Displaying the Contents: ";
    display<int>(v);

    //Removing 4th and 5th element
    v.erase(v.begin()+3, v.begin()+5);

    //Display the content
    cout << "Displaying the Contents: ";
    display<int>(v);

    return 0;
}