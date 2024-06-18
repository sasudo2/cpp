#include <iostream>

using namespace std;


class Vector{
    private:
    static const int size = 3;
    int v[size];
    public:
    Vector(){
        for(int i = 0; i < size; i++){
            v[i] = 0;
        }
    }
    Vector(int *a){
        for(int i = 0; i < size; i++){
            v[i] = a[i];
        }
    }

    friend Vector operator * (Vector, int);
    friend Vector operator * (int, Vector);
    friend istream & operator >> (istream &, Vector &);
    friend ostream & operator << (ostream &, Vector &);
    
};

Vector operator * (Vector b, int a){
    Vector temp;
    for(int i = 0; i < b.size; i++){
        temp.v[i] = b.v[i] * a;
    }
    return temp;
}

Vector operator * (int a, Vector b){
    Vector temp;
    for(int i = 0; i < b.size; i++){
        temp.v[i] = b.v[i] * a;
    }
    return temp;
}

istream & operator >> (istream & bin, Vector & a){
    for(int i = 0; i < a.size; i++){
        bin >> a.v[i];
    }
    return (bin);
}


ostream & operator << (ostream & bout, Vector & b){
    for(int i = 0; i < b.size; i++){
        bout << b.v[i] << ",";
    }
    bout << endl;
    return (bout);
}

int main(){
    int x[3] = {2, 4, 5};
    Vector v1(x);
    Vector v2;

    cin >> v2;

    cout << v1;
    cout << v2;
    v1 = v1 * 3;
    cout << v1;
    return 0;
}