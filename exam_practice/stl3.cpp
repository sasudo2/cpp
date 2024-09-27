#include <iostream>

using namespace std;

template <class t, int s>
class Array{
    private:
    t *a;
    int size = s;
    public:
    Array(t *x){
        a = new t[s];
        for(int i = 0 ; i < s; i++){
            a[i] = x[i];
        }
    }
    void display(){
        cout << "array: " ;
        for(int i = 0; i < size; i++){
            cout << a[i] << " ";
        }
    }
    void sort(){
        for(int i = 0; i < size; i++){
            for(int j = i; j < size; j++){
                if(a[i] > a[j]){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    t max(){
        t m = a[0];
        for(int i = 0; i < size; i++){
            if(a[i] > m){
                m = a[i];
            }
        }
        return m;
    }
    t min(){
        t m = a[0];
        for(int i = 0; i < size; i++){
            if(a[i] < m){
                m = a[i];
            }
        }
        return m;
    }
};

int main(){
    int x[4] = {2, 4, 1, 6};
    Array<int, 4> a = x;
    a.display();
    cout << "max: " << a.max();
    cout << "min: " << a.min();
    a.sort();
    cout <<"sorted array" << endl;
    a.display();
    return 0;
}