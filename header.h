#include<bits/stdc++.h>

using namespace std;
class bankAccount{
private:
    string name;
    int serial;
    string accNo;
    string accType;
    float balance;
    static int noOfAccounts;
public:
	void setName(string inputName);
    void setAccNo(string inputAccNo);
    void setSerial(int srno);
    void setAccType(string inputAccType);
    void setBalance(float inputBalance);

	string getName();
    int getSerial();
    string getAccNo();
    string getAccType();
    float getBalance();
    static int getNoOfAccounts();
    static void incrementAccounts();
    void deposit(float amount);
    void withdraw(float amount);
    void display();
    void setupAccount();
    bankAccount();
    
    //constructors
    bankAccount(string inputName,string inputAccNo,string inputAccType,float inputBalance,int srno);
    bankAccount(bankAccount &b);

};
