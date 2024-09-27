#include <iostream>

using namespace std;

template <class t>
class MyStack{
    public:
    t *s = nullptr;
    int size = 0;
    public:
    void push(t);
    t pop();
    void display();
};

template <class t>
void MyStack<t>::push(t a){
    if(size == 0){
        s = new t[1];
        s[0] = a;
        size = 1;
    }
    else{
        t *temp = new t[size];
        for(int i = 0; i < size; i++){
            temp[i] = s[i];
        }
        size = size + 1;
        s = new t[size];
        for(int i = 0; i < size - 1; i++){
            s[i] = temp[i];
        }
        s[size - 1] = a;
        delete(temp);

    }
}

template <class t>
t MyStack<t>::pop(){
    if(size == 0){
        return 0;
    }
    else{
        t x = s[size - 1];
        size = size - 1;
        t *temp = new t[size];
        
        for(int i = 0; i < size; i++){
            temp[i] = s[i];
        }
        s = new t[size];
        for(int i = 0; i < size; i++){
            s[i] = temp[i];
        }
        delete(temp);
        return x;
    }
}

template <class t>
void MyStack<t>::display(){
    cout << "current stack: " << endl;
    for(int i = 0; i < size; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

int main(){
    MyStack<int> s;
    s.push(3);
    s.push(5);
    s.push(6);
    s.push(12);
    s.display();
    s.pop();
    s.pop();
    s.display();
    return 0;
}