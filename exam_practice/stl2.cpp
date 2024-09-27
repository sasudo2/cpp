#include <iostream>

using namespace std;

template <class t>
class vector{
    private:
    t *v;
    int size;
    public:
    vector(){
        size = 0;
        v = nullptr;
    }
    void push_back(t x){
        if(size == 0){
            size = 1;
            v = new t[size];
            v[0] = x;
        }
        else{
        t *temp = new t[size];
        int temp_size = size;
        for(int i = 0; i < size; i++){
            temp[i] = v[i];
        }
        size = size + 1;
        v = new t[size];
        for(int i = 0; i < temp_size; i++){
            v[i] = temp[i];
        }
        v[size-1] = x;
        delete(temp); 
        }
    }
    void display(){
        cout << "vector: ";
        for(int i = 0; i < size; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    t operator *(vector<t> &a){
        if(size <= a.size){
            t x = 0;
            for(int i = 0; i < size; i++){
                x += v[i] * a.v[i];
            }
            return x;
        }
        else{
            t x = 0;
            for(int i = 0; i < a.size; i++){
                x += v[i] * a.v[i];
            }
            return x;
        }
        
    }

};

int main(){
    vector<int> i1, i2;
    i1.push_back(2);
    i1.push_back(3);
    i2.push_back(4);
    i2.push_back(5);
    i1.display();
    i2.display();
    int x = i1 * i2;
    cout << "i1 * i2 = " << x;
    vector<double> d1, d2;
    d1.push_back(2.45);
    d1.push_back(3.32);
    d2.push_back(4.234);
    d2.push_back(5.56);
    d1.display();
    d2.display();
    double y = d1 * d2;
    cout << "d1 * d2 = " << y;

    return 0;
}