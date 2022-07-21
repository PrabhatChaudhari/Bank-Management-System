/*prabhat chaudhari
Rno BT19CSE020*/
#include<iostream>
#include<string>

using namespace std;
class bankAccount{
private:
    string name;
    int accNo;
    string accType;
    float balance;
    static int noOfAccounts;
public:
	string getName();
    int getAccNo();
    string getAccType();
    float getBalance();
    static int getNoOfAccounts();
    static void incrementAccounts();
    void deposit(float amount);
    void withdraw(float amount);
    void display();
    void setupAccount();
    bankAccount();
    bankAccount(string inputName,int inputAccNo,string inputAccType,float inputBalance);
    bankAccount(bankAccount &b);
    void setName(string inputName);
    void setAccNo(int inputAccNo);
    void setAccType(string inputAccType);
    void setBalance(float inputBalance);

};

