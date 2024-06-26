#include <iostream>

using namespace std;

class Matrix{
    int **m;
    static const int size = 2;
    public:
    Matrix(){
        m = new int *[size];
        for(int i = 0; i < size; i++){
           m[i] = new int[size]; 
        }
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                m[i][j] = 0;
            }
        }
    }
    Matrix(int *a){
        m = new int *[size];
        for(int i = 0; i < size; i++){
           m[i] = new int[size]; 
        }
        m[0][0] = a[0];
        m[0][1] = a[1];
        m[1][0] = a[2];
        m[1][1] = a[3];
    }
    Matrix(Matrix &a){
        m = new int *[size];
        for(int i = 0; i < size; i++){
           m[i] = new int[size]; 
        }
        for(int i = 0; i<size; i++){
            for(int j = 0; j < size; j++){
                m[i][j] = a.m[i][j];
            }
        }
    }

    Matrix operator -(Matrix &a){
        Matrix temp;
        for(int i = 0; i<size; i++){
            for(int j = 0; j < size; j++){
                for(int k = 0; k < size; k++){
                temp.m[i][j] += m[i][k] * a.m[k][j];
                }
            }
        }
        return temp;
    }

    void display(){
        cout << m[0][0] << " " << m[0][1] << endl 
        << m[1][0] << " " << m[1][1] << endl;
    }
};

int main(){
    int a[4] = {1, 2, 3, 4};
    Matrix m1(a);
    int b[4];
    for(int i = 0 ; i < 4; i++){
        cout << "enter a number: ";
        cin >> b[i];
    }
    Matrix m2(b);
    Matrix m3 = m1 - m2;
    m3.display();

}