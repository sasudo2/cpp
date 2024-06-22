#include <iostream>
#include <string.h>
using namespace std;
class account{
    protected:
    char *name;
    unsigned int accountNumber;
    char *type;
    float balance = 0;
    public:
    account(const char *a,unsigned int b, const char *c){
        strcpy(name, a);
        accountNumber = b;
        strcpy(type, c);
    }
    float deposit(float a){
        balance = balance + a;
        return balance;
    }
    void displayBalance(){
        cout << "Balance: " << balance << endl;
    }
};

class cur_acct: public account{
    public:
    cur_acct(const char *a, unsigned int b):account(a, b, "current account"){
        
    }
};