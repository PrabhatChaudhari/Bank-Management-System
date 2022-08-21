/*Prabhat Dinkar Chaudhari
BT19CSE020*/

#include <bits/stdc++.h>
#include "header.h"
using namespace std;

struct Node
{
    bankAccount account;
    Node *left;
    Node *right;

    Node(bankAccount acc)
    {
        account = acc;
        this->left = NULL;
        this->right = NULL;
    }
};

int total = 0;
// for setting up bank account

bankAccount::bankAccount()
{
    setAccNo("");
    setAccType("");
    setBalance(0.0);
    setName("");
    setSerial(0);
}
// constructor
bankAccount::bankAccount(string inputName, string inputAccNo, string inputAccType, float inputBalance, int srno)
{
    setName(inputName);
    setAccNo(inputAccNo);
    setAccType(inputAccType);
    setBalance(inputBalance);
    setSerial(srno);
}
// copy constructor
bankAccount::bankAccount(bankAccount &b)
{
    setName(b.getName());
    setAccNo(b.getAccNo());
    setAccType(b.getAccType());
    setBalance(b.getBalance());
    setSerial(b.getSerial());
}

void bankAccount::setName(string inputName)
{
    name = inputName;
}
void bankAccount::setAccNo(string inputAccNo)
{
    accNo = inputAccNo;
}
void bankAccount::setSerial(int srno)
{
    serial = srno;
}
void bankAccount::setAccType(string inputAccType)
{
    accType = inputAccType;
}
void bankAccount::setBalance(float inputBalance)
{
    balance = inputBalance;
}
string bankAccount::getName()
{
    return name;
}
string bankAccount::getAccType()
{
    return accType;
}
int bankAccount::getSerial()
{
    return serial;
}
string bankAccount::getAccNo()
{
    return accNo;
}
float bankAccount::getBalance()
{
    return balance;
}

void bankAccount::deposit(float amount)
{
    float bal = getBalance();
    bal = bal + amount;
    setBalance(bal);
    cout << "\n\t\t\t\t     *** SUCCESSFULLY DEPOSITED " << amount << "RS. ****\n";
}
void bankAccount::withdraw(float amount)
{
    float bal = getBalance();
    if (amount > bal)
    {
        cout << "\n\t\t\t\t     !!! INSUFFICIENT BALANCE !!!\n";
    }
    else
    {
        bal = bal - amount;
        setBalance(bal);
        cout << "\n\t\t\t\t     *** SUCCESSFULLY WITHDRAWN " << amount << " RS. ***\n";
    }
}

void bankAccount::display()
{
    cout<<endl;
    cout << "\t\t\t\t*                                *"<<endl;
    cout << "\t\t\t\t\t NAME:      " << getName() << endl;
    cout << "\t\t\t\t\t BALANCE:   " << getBalance() << endl;
    cout << "\t\t\t\t\t ACC NO.    " << getAccNo() << endl;
    cout << "\t\t\t\t\t ACC TYPE:  " << getAccType() << endl;
    cout << "\t\t\t\t*                                *"<<endl;
}

Node *createAccount(bankAccount child, Node *root, int srno)
{
    if (root == NULL)
    {
        Node *temp = new Node(child);
        return temp;
    }
    if (srno < root->account.getSerial())
    {
        root->left = createAccount(child, root->left, srno);
    }
    if (srno > root->account.getSerial())
    {
        root->right = createAccount(child, root->right, srno);
    }
    return root;
}

Node *findAccount(Node *root, int srno)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (srno == root->account.getSerial())
    {
        return root;
    }
    if (srno < root->account.getSerial())
    {
        return findAccount(root->left, srno);
    }
    if (srno > root->account.getSerial())
    {
        return findAccount(root->right, srno);
    }
    return root;
}

bankAccount minAcc(Node *root)
{
    if (root->left == NULL)
    {
        return root->account;
    }
    return minAcc(root->left);
}
Node *deleteAccount(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->account.getSerial())
        root->left = deleteAccount(root->left, key);
    else if (key > root->account.getSerial())
        root->right = deleteAccount(root->right, key);
    else
    {
        if (root->right == NULL)
            return root->left;
        else if (root->left == NULL)
            return root->right;
        else
        {
            root->account = minAcc(root->right);
            root->right = deleteAccount(root->right, root->account.getSerial());
        }
    }
    return root;
}

void displayList(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    int space = 15;
    string temp = root->account.getAccNo();
    space = space - temp.length();
    cout << "\t\t\t\t" << root->account.getSerial() << " | " << root->account.getAccNo();
    for (int i = 0; i < space; i++)
    {
        cout << " ";
    }
    cout << "| " << root->account.getName() << endl;
    displayList(root->left);
    displayList(root->right);
}

int main()
{
    Node *holder = NULL;

    unordered_map<string, int> accountInfo;
    string inputAccNo;
    int option, i, found, n, flag = 0;
    float amount;
    Node* temp;
    cout << "\n\n\t\t\t\t\tBANK MANAGEMENT SYSTEM" << endl
         << endl;
    do
    {
        if (flag != 0)
        {
            cout << endl
                 << endl
                 << "\t\t\t******************************************************************" << endl
                 << endl;
        }
        flag = 1;
        cout << "\t\t\t\t ________________________________________\n";
        cout << "\t\t\t\t|                                        |\n";
        cout << "\t\t\t\t|  1. Setup Account                      |\n";
        cout << "\t\t\t\t|  2. Display Name and Balance           |\n";
        cout << "\t\t\t\t|  3. Withdraw                           |\n";
        cout << "\t\t\t\t|  4. Deposit                            |\n";
        cout << "\t\t\t\t|  5. Transfer money to another account  |\n";
        cout << "\t\t\t\t|  6. Modify existing account            |\n";
        cout << "\t\t\t\t|  7. Close  Existing Account            |\n";
        cout << "\t\t\t\t|  8. Display all accounts               |\n";
        cout << "\t\t\t\t|  9. Quit                               |\n";
        cout << "\t\t\t\t ________________________________________\n";

        cout << "\n\t\t\t\t\tENTER OPTION:   ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
        {

            string inputName, inputAccType;
            cout << "\t\t\t\tNAME OF THE ACCOUNT HOLDER:    ";
            cin >> inputName;
            cout << endl;
            cout << "\t\t\t\tTYPE OF ACCOUNT (current/savings): ";
            cin >> inputAccType;
            cout << endl;
            cout << "\t\t\t\tACCOUNT NUMBER:  ";
            cin >> inputAccNo;

            total++;

            bankAccount account(inputName, inputAccNo, inputAccType, 0.0, total);
            accountInfo[inputAccNo] = total;
            holder = createAccount(account, holder, total);

            cout << endl
                 << "\t\t\t\t     *** ACCOUNT HAS BEEN CREATED SUCCESSFULLY ***" << endl;
            break;
        }
        case 2:
        {
            cout << "\t\t\t\tENTER ACCOUNT NUMBER:";
            cin >> inputAccNo;
            found = i = 0;
            int key = accountInfo[inputAccNo];

            temp = findAccount(holder, key);
            if (temp != NULL)
            {
                temp->account.display();
            }
            else
            {
                cout << "\t\t\t\t     !!! ACCOUNT NOT FOUND !!!";
            }
            break;
        }
        case 3:
        {
            cout << "\t\t\t\tENTER ACCOUNT NUMBER:";
            cin >> inputAccNo;
            int amount;
            found = i = 0;
            int key = accountInfo[inputAccNo];

            temp = findAccount(holder, key);
            if (temp != NULL)
            {
                cout << "\t\t\t\tENTER AMOUNT: ";
                cin >> amount;
                temp->account.withdraw(amount);
            }
            else
            {
                cout << "\t\t\t\t     !!! ACCOUNT NOT FOUND! ENTER VALID CREDENTIALS. !!!";
            }
            break;
        }
        case 4:
        {
            cout << "\t\t\t\tENTER ACCOUNT NUMBER:";
            cin >> inputAccNo;
            int amount;
            found = i = 0;
            int key = accountInfo[inputAccNo];

            temp = findAccount(holder, key);
            if (temp != NULL)
            {
                cout << "\t\t\t\tENTER AMOUNT: ";
                cin >> amount;
                temp->account.deposit(amount);
            }
            else
            {
                cout << "\n\t\t\t\t     !!! ACCOUNT NOT FOUND! ENTER VALID CREDENTIALS. !!!";
            }
            break;
        }
        case 5:
        {
            cout << "\t\t\t\tENTER ACCOUNT NUMBER:";
            cin >> inputAccNo;
            int amount;
            string receiverAccNo;
            int key = accountInfo[inputAccNo];
            temp = findAccount(holder,key);
            if (temp != NULL)
            {
                cout << "\t\t\t\tENTER ACCOUNT NO. OF RECEIVER: ";
                cin >> receiverAccNo;
                int receiverKey = accountInfo[receiverAccNo];
                Node* receiverNode = findAccount(holder, receiverKey);
                if (receiverNode != NULL)
                {
                    cout << "\t\t\t\tENTER AMOUNT: ";
                    cin >> amount;
                    if(temp->account.getBalance() >= amount)
                    {
                        temp->account.withdraw(amount);
                        receiverNode->account.deposit(amount);
                        cout << "\n\t\t\t\t     ***  RS. "<<amount<<"TRANSFER SUCCESSFULL ***\n";
                    }
                    else
                    {
                        temp->account.withdraw(amount);
                        break;
                    }
                }
                else
                {
                    cout << "\n\t\t\t\t     !!! Receiver ACCOUNT NOT FOUND! ENTER VALID CREDENTIALS. !!!";
                }
            }
            else
            {
                cout << "\n\t\t\t\t     !!! ACCOUNT NOT FOUND! ENTER VALID CREDENTIALS. !!!";
            }
            break;            
        }
        case 6:
        {
            cout << "\t\t\t\tENTER YOUR ACCOUNT NUMBER :";
            cin >> inputAccNo;
            cout << endl;
            int opt = 0;
            do
            {            
                cout << "\t\t\t\t|  1. Update Name of the account holder|\n";
                cout << "\t\t\t\t|  2. Update account type|\n";
                cout << "\t\t\t\t|  3. Cancel\n";
                cout<< "\t\t\t\tENTER YOUR OPTION : ";
                cin>>opt;
                switch (opt)
                {
                    case 1:
                    {
                        string newName;
                        cout<< "\t\t\t\tNAME UPDATE TO: ";
                        cin>>newName;
                        int key = accountInfo[inputAccNo];
                        temp = findAccount(holder, key);
                        if (temp != NULL)
                        {
                            temp->account.setName(newName);
                            cout<< "\t\t\t\t     *** ACCOUNT HAS BEEN UPDATED SUCCESSFULLY ***" << endl;
                        }
                        else
                        {
                            cout << "\t\t\t\t     !!! ACCOUNT NOT FOUND! ENTER VALID CREDENTIALS. !!!";
                        }                        
                        break;
                    }
                    case 2:
                    {
                        string newType;
                        cout<< "\t\t\t\tACCOUNT TYPE UPDATE TO: ";
                        cin>>newType;
                        int key = accountInfo[inputAccNo];
                        temp = findAccount(holder, key);
                        if (temp != NULL)
                        {
                            temp->account.setAccType(newType);
                            cout<< "\n\t\t\t\t     *** ACCOUNT HAS BEEN UPDATED SUCCESSFULLY ***" << endl;
                        }
                        else
                        {
                            cout << "\n\t\t\t\t     !!! ACCOUNT NOT FOUND! ENTER VALID CREDENTIALS. !!!";
                        }                        
                        break;
                    }
                    case 3:
                    {
                        break;
                    }
                    default:
                        cout << "\t\t\t\t     !!! INVALID OPTION RE-ENTER. !!!"<<endl;
                        break;
                }
            } while (opt!=3);
            break;
            
        }        
        case 7:
        {
            cout << "\t\t\t\tENTER ACCOUNT NUMBER: ";
            cin >> inputAccNo;
            if (accountInfo[inputAccNo] == 0)
            {
                cout << "\n\t\t\t\t     !!! ACCOUNT NOT FOUND! ENTER VALID CREDENTIALS. !!!";
                break;
            }
            string choice;
            cout << "\t\t\t\t\tDo you want to delete this account (YES/NO): ";
            cin >> choice;
            cout << endl;
            if (choice == "YES" || choice == "yes" || choice == "Y" || choice == "y")
            {
                int key = accountInfo[inputAccNo];
                accountInfo[inputAccNo] = 0;
                holder = deleteAccount(holder, key);
                cout << endl
                    << "\n\t\t\t\t     *** ACCOUNT HAS BEEN DELETED SUCCESSFULLY ***" << endl;
            }

            break;
        }
        case 8:
        {
            displayList(holder);
            break;
        }
        case 9:
        {
            break;
        }
        default:
        {
            cout << "\n\t\t\t\t     !!! INVALID OPTION !!!";
            break;
        }
        }
    } while (option != 9);
}
