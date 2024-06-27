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
        name = new char[strlen(a)];
        strcpy(name, a);
        accountNumber = b;
        type = new char[strlen(c)];
        strcpy(type, c);
    }
    float deposit(float a){
        balance = balance + a;
        cout << "new balance: " << balance << endl;
        return balance;
    }
    void displayBalance(){
        cout << "Balance: " << balance << endl;
    }
    void accountinfo(){
        cout << "account holder: " << name << endl;
        cout << "account type: " << type << endl;
        cout << "account number: " << accountNumber << endl;
        cout << "balance: " << balance << endl;
    }
};

class cur_acct: public account{
    public:
    cur_acct(const char *a, unsigned int b, float bal):account(a, b, "current account"){
        balance = bal;
    }
    void withdraw(float i){
        if(balance <= 0){
            cout << "balance: " << balance <<endl;
            cout << "not enough balance!!!" << endl;
            return;
        }
        else if(balance < i){
            cout << "not enough balance!!!" << endl;
            return;
        }
        else if(balance >= i){
            balance  = balance - i;
            cout << "withdrawn: " << i << endl;
            cout << "new balance: " << balance << endl;
            if(balance < 100){
                cout << "balance less then 100" << endl;
                cout << "applying 5% charge" << endl;
                balance  = balance - balance*5/100 ;
            }
            return;
        }
    }
};

class sav_acct: public account{
    public:
    sav_acct(const char *a, unsigned int b, float bal):account(a, b, "saving account"){
        balance = bal;
    }
    void withdraw(float i){
        if(balance <= 0){
            cout << "balance: " << balance <<endl;
            cout << "not enough balance!!!" << endl;
            return;
        }
        else if(balance < i){
            cout << "not enough balance!!!" << endl;
            return;
        }
        else if(balance >= i){
            balance  = balance - i;
            cout << "withdrawn: " << i << endl;
            cout << "new balance: " << balance << endl;
            return;
        }
    }
};

int main(){
    sav_acct ac1("sanjay", 123412, 200);
    cur_acct ac2("sanja", 123434, 120);
    ac1.accountinfo();
    ac2.withdraw(40);
    ac1.deposit(300);
    ac2.accountinfo();
    return 0;
}