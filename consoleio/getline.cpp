#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int size = 20;
    char city[size];

    cout << "Enter the name of city: ";
    cin >> city;
    cout << "City: " << city << endl;
    cin.ignore();
    cout << "Enter the name of city: ";
    cin.getline(city, size);
    cout << "City: " << city << endl;

    return 0;
}