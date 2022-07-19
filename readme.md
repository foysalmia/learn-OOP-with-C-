
# OOP Practise With C++

It is a simple project to Practise c++ in OOP concept.It is a row code project in c++.



## Features

- User can creat a new account
- User can add money
- User can withdraw money
- User can add money to a mobile bank such as bkash or Nogod in Bangladesh


## 🚀 About Me
I'm Foysal who is a curious programmer....


## Usage/Examples

```javascript
#include <iostream>

using namespace std;

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
```

