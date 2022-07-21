#include<iostream>
#include<string>
#include"header.h"

using namespace std;
int main()
{
    bankAccount holders[50];
    int option,inputAccNo,i,found,n;
    float amount;
    do
    {
        cout<<"What you want to do?\n";
        cout<<"1.Setup Account\n";
        cout<<"2.Display Name and Balance\n";
        cout<<"3.Withdraw\n";
        cout<<"4.Deposit\n";
        cout<<"5.Quit\n";
        cout<<"\nEnter option:";
        cin>>option;
        switch(option)
        {
            case 1: {
                        holders[bankAccount::getNoOfAccounts()].setupAccount();
                        bankAccount::incrementAccounts();
                        break;
                    }
            case 2: {
                        cout<<"ENTER ACCOUNT NUMBER:";
                        cin>>inputAccNo;
                        found=i=0;
                        n=bankAccount::getNoOfAccounts();
                        while(i<n && !found)
                        {
                           if(holders[i].getAccNo()==inputAccNo)
                           {
                              found=1;
                           }
                           i++;

                        }
                        if(found==1)
                        {
                            holders[i-1].display();
                        }
                        else
                        {
                            cout<<"Account not found";
                        }
                        break;
                    }
            case 3: {
                        cout<<"ENTER ACCOUNT NUMBER:";
                        cin>>inputAccNo;
                        found=i=0;
                        n=bankAccount::getNoOfAccounts();
                        while(i<n && !found)
                        {
                           if(holders[i].getAccNo()==inputAccNo)
                           {
                              found=1;
                           }
                           i++;

                        }
                        if(found==1)
                        {
                            cout<<"ENTER AMOUNT:";
                            cin>>amount;
                            holders[i-1].withdraw(amount);
                        }
                        else
                        {
                            cout<<"Account not found";
                        }
                       break;
                   }
            case 4: {
                       cout<<"ENTER ACCOUNT NUMBER:";
                        cin>>inputAccNo;
                        found=i=0;
                        n=bankAccount::getNoOfAccounts();
                        while(i<n && !found)
                        {
                           if(holders[i].getAccNo()==inputAccNo)
                           {
                              found=1;
                           }
                           i++;

                       }
                       if(found==1)
                       {
                           cout<<"ENTER AMOUNT:";
                           cin>>amount;
                           holders[i-1].deposit(amount);
                       }
                       else
                       {
                           cout<<"Account not found";
                       }
                       break;
                    }
            case 5: {
			         	break;
			        }
            default :{
                        cout<<"INVALID OPTION";
                        break;
                     }
        }
    }while(option!=5);

}
