#include<bits/stdc++.h>

using namespace std;

class Bank
{
private:
    string password;
protected:
    int balance;
public:
    string name;
    int age;
    string address;
    int accountNumber;
    int getBalance()
    {
        return balance;
    }
    Bank(string name,int age,string address,string password)
    {
        this->name = name;
        this->age = age;
        this->address = address;
        this->password = password;
        this->balance = 0;
        this->accountNumber = rand()%1000000000;
    };
    void setBalance(string pass,int amount)
    {
        if(pass == password)
        {
            this->balance += amount;
            cout<<"Amount added successfully"<<endl;
        }
        else
        {
            cout<<"Password did not matched..!"<<endl;
        }
    };
    void withdraw(string pass,int amount)
    {
        if(pass == password)
        {
            if(amount>this->balance){
                cout<<"Insufficient Balance"<<endl;
                return;
            }
            this->balance -= amount;
            cout<<"Amount withdraw successfully done"<<endl;
        }
        else
        {
            cout<<"Password did not matched..!"<<endl;
        }
    };

    friend class Bkash;

};

class Bkash{
private:
    int money;
public:

    Bkash(Bank *account,string pass,int amount){
        money = 0;
        if(pass == account->password){
            money += amount;
            account->withdraw(pass,amount);
        }
    }
    void showMoney(){
        cout<<money<<endl;
    }
};

Bank *create_account()
{
    string password;
    string name;
    int age;
    string address;
    cout<<"Create New Account : << Name Age Address Password >> "<<endl;
    cin>>name>>age>>address>>password;
    Bank *myAccount = new Bank(name,age,address,password);
    return myAccount;
}

Bkash *create_bkash(Bank *account){
    string pass;
    int amount;
    cout<<"Add money to Bkash <<Pass Amount>>"<<endl;
    cin>>pass>>amount;
    Bkash *bkash = new Bkash(account,pass,amount);
    return bkash;
}

void addMoney(Bank *account)
{
    int amount;
    string pass;
    cout<<"ADD Money "<<endl;
    cin>>amount>>pass;
    account->setBalance(pass,amount);
}

void Deposite(Bank *account)
{
    int amount;
    string pass;
    cout<<"Deposite Money "<<endl;
    cin>>amount>>pass;
    account->withdraw(pass,amount);
}

void print(Bank *myAccount)
{
    cout<<myAccount->name<<" "<<myAccount->getBalance()<<" "<<myAccount->age<<" "<<myAccount->address<<" "<<myAccount->accountNumber<<endl;
}

int main()
{
    Bank *myAccount = create_account();
    addMoney(myAccount);
    Deposite(myAccount);
    Bkash *bkash = create_bkash(myAccount);
    cout<<"Bkash Money"<<endl;
    bkash->showMoney();
    print(myAccount);
    return 0;
}
