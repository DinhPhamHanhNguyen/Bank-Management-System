#include "Bank_Account.h"
#include <iostream>

Bank_Account::Bank_Account()
{
    account_holder_name = "";
    account_number = 0;
    balance = 0.0;
}

void Bank_Account::deposit(float balance)
{
    this->balance += balance;
}

void Bank_Account::withdraw(float balance)
{
    this->balance -= balance;
}

void Bank_Account::set_name(string name)
{
    this->account_holder_name = name;
}

void Bank_Account::set_account_number(int account_number)
{
    this->account_number = account_number;
}

int Bank_Account::get_account_number()
{
    return account_number;
}

float Bank_Account::get_balance()
{
    return balance;
}

void Bank_Account::display()
{
    cout << "Account holder name: " << account_holder_name << endl;
    cout << "Account number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
}
