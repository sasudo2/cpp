#include <iostream>
using namespace std;
#define PI 3.1415

int main(){
    float degree, radian;
    std::cout << "input the angle in degree: ";
    std::cin >> degree;
    radian = degree*PI/180;
    std::cout << "Angel in radian: " << radian;
    return 0;
}