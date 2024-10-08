#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account
{
    string name;
    int accountNumber;
    double balance;

public:
    Account(string name, int accountNumber, double balance)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposite(double amount)
    {
        balance = balance + amount;
        cout << "Your Account is Credited by Amount : " << amount << endl;
        cout << "Your Total Balance is : " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Reamining Amount is : " << balance << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient Balance" << endl;
        }
        else
        {
            cout << "Invalid amount" << endl;
        }
    }

    void details(int accountNumber)
    {
        cout << "Name : " << name << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance : " << balance << endl;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }
};

class Bank
{
    vector<Account> accounts;
    int nextAccountNumber = 1001;

public:
    void createAccount(string name, double intialAmount)
    {
        Account newAccount(name, nextAccountNumber++, intialAmount);
        accounts.push_back(newAccount);
        cout << "Your Account is Created Succefully. Your Account Number is " << nextAccountNumber - 1 << endl;
        cout << " Your balance is : " << intialAmount << endl;
        return;
    }

    void depositeMoney(int accountNumber, double initialAmount)
    {
        for (auto &account : accounts)
        {
            if (account.getAccountNumber() == accountNumber)
            {
                account.deposite(initialAmount);
                cout << "Your Account is Credited Amount " << initialAmount << endl;
                return;
            }
        }
        cout << "Account Not Found" << endl;
    }

    void withdrawMoney(int accountNumber, int amount)
    {
        for (auto &account : accounts)
        {
            if (account.getAccountNumber() == accountNumber)
            {
                account.withdraw(amount);
                return;
            }
        }

        cout << "Account Not found" << endl;
    }

    void checkBalance(int accountNumber)
    {
        for (auto &account : accounts)
        {
            if (account.getAccountNumber() == accountNumber)
            {
                account.details(accountNumber);
                return;
            }
        }
        cout << "Account Not Found" << endl;
    }

    void showAllAccount()
    {
        cout << "All Accounts : " << endl;

        if (accounts.empty())
        {
            cout<<endl<<"!!  Please first Create Accounts for data  !!"<<endl;
        }
        else
        {
            for (auto &account : accounts)
            {
                cout<<account.getAccountNumber()<<endl<<endl;
            }
        }
    }
};

int main()
{
    string name;
    int accountNumber;
    double amount;
    int choise;

    Bank b;

    do
    {
        cout << endl
             << endl
             << endl;
        cout << "!! Welcome to Banking Application !!" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposite Amount" << endl;
        cout << "3. WithDraw Ammount" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Show All Accounts " << endl;

        cout << "6. Exit " << endl;

        cout << endl
             << endl;

        cout << "Enter Your Choise : ";
        cin >> choise;

        switch (choise)
        {

        case 1:
            cin.ignore();
            cout << "Enter your Name : ";
            getline(cin, name);
            cout << "Enter Your Initial Amount : ";
            cin >> amount;
            b.createAccount(name, amount);
            break;

        case 2:
            cout << "Enter Your Account Number : ";
            cin >> accountNumber;
            cout << "Enter Your deposite Amount : ";
            cin >> amount;
            b.depositeMoney(accountNumber, amount);
            break;

        case 3:
            cout << "Enter Your Account Number : ";
            cin >> accountNumber;
            cout << "Enter Your Withdraw Amount : ";
            cin >> amount;
            b.withdrawMoney(accountNumber, amount);
            break;

        case 4:
            cout << "Enter Your Account Number : ";
            cin >> accountNumber;
            b.checkBalance(accountNumber);
            break;

        case 5:
            b.showAllAccount();
            break;

        case 6:
            cout << "Thankyou for visiting Banking Application." << endl;
            break;

        default:
            cout << "Please Enter Correct Choise" << endl;
            break;
        }
    } while (choise != 6);

    return 0;
}