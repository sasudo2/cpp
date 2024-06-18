#include <iostream>
using namespace std;
int main(){
    float input, output;
    int choice;
    std::cout << "enter 1 for celsius to fahrenheit conversion \nenter 2 for fahrenheit to celsius conversion \n: ";
    std::cin >> choice;
    if(choice == 1) {
        std::cout << "enter the temperature in celsius: ";
        std::cin >> input;
        output = 9*input/5+32;
        std::cout << "temperature in fahrenheit is: " << output;
    }
    else if(choice == 2) {
        std::cout << "enter the temperature in fahrenheit: ";
        std::cin >> input;
        output = (input-32)*5/9;
        std::cout << "temperature in celsius is: " << output;
    }
    else{
        std::cout << "invalid";
    }
    return 0;

}