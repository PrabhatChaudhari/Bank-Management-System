#include<iostream>
#include<string>
#include"header.h"

using namespace std;



int bankAccount::noOfAccounts=0;
bankAccount::bankAccount()
{
    setAccNo(0);
    setAccType("");
    setBalance(0.0);
    setName("");
}

bankAccount::bankAccount(string inputName,int inputAccNo,string inputAccType,float inputBalance)
{
    setName(inputName);
    setAccNo(inputAccNo);
    setAccType(inputAccType);
    setBalance(inputBalance);
}
bankAccount::bankAccount(bankAccount &b)
{
    setName(b.getName());
    setAccNo(b.getAccNo());
    setAccType(b.getAccType());
    setBalance(b.getBalance());
}

void bankAccount::setName(string inputName)
{
    name=inputName;
}
void bankAccount::setAccNo(int inputAccNo)
{
    accNo=inputAccNo;
}
void bankAccount::setAccType(string inputAccType)
{
    accType=inputAccType;
}
void bankAccount::setBalance(float inputBalance)
{
    balance=inputBalance;
}
string bankAccount::getName()
{
    return name;
}
string bankAccount::getAccType()
{
    return accType;
}
int bankAccount::getAccNo()
{
    return accNo;
}
float bankAccount::getBalance()
{
    return balance;
}
int bankAccount::getNoOfAccounts()
{
    return noOfAccounts;
}
void bankAccount::incrementAccounts()
{
    noOfAccounts++;
}
void bankAccount::deposit(float amount)
{
    float bal=getBalance();
    bal+=amount;
    setBalance(bal);
    cout<<"SUCCESSFULLY DEPOSITED "<<amount<<"RS.\n";
}
void bankAccount::withdraw(float amount)
{
    float bal=getBalance();
    if(amount>bal)
    {
        cout<<"INSUFFICIENT BALANCE\n";
    }
    else
    {
        bal-=amount;
        setBalance(bal);
        cout<<"SUCCESSFULLY WITHDRAWN "<<amount<<" RS.\n";
    }
}

void bankAccount::display()
{
    cout<<"NAME:"<<getName()<<"\n";
    cout<<"BALANCE:"<<getBalance()<<"\n";
}
//for setting up bank account
void bankAccount::setupAccount()
{
    string inputName,inputAccType;
    int inputAccNo;
    cout<<"ENTER NAME:";
    cin.ignore();
    getline(cin,inputName);
    setName(inputName);
    cout<<"ENTER ACCOUNT TYPE:";
    cin>>inputAccType;
    setAccType(inputAccType);
    cout<<"ENTER ACCOUNT NUMBER:";
    cin>>inputAccNo;
    setAccNo(inputAccNo);
}


