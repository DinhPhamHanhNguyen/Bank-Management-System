#include "Bank_System.h"
#include <iostream>

Bank_System::Bank_System()
{
    bank_accounts = vector<Bank_Account *>();
}
void Bank_System::add_bank_account(Bank_Account *bank_account)
{
    bank_accounts.push_back(bank_account);
}

void Bank_System::remove_bank_account(int account_number)
{
    for (int i = 0; i < bank_accounts.size(); i++)
    {
        if (bank_accounts[i]->get_account_number() == account_number)
        {
            bank_accounts.erase(bank_accounts.begin() + i);
            break;
        }
    }
}

void Bank_System::deposit_money(int account_number, float amount)
{
    Bank_Account *bank_account = get_bank_account(account_number);
    bank_account->deposit(amount);
}

void Bank_System::withdraw_money(int account_number, float amount)
{
    Bank_Account *bank_account = get_bank_account(account_number);
    bank_account->withdraw(amount);
}

Bank_Account *Bank_System::get_bank_account(int account_number)
{
    for (int i = 0; i < bank_accounts.size(); i++)
    {
        if (bank_accounts[i]->get_account_number() == account_number)
        {
            return bank_accounts[i];
        }
    }
    return NULL;
}

void Bank_System::display_all_bank_accounts()
{
    for (int i = 0; i < bank_accounts.size(); i++)
    {
        std::cout << "Account " << i + 1 << std::endl;
        bank_accounts[i]->display();
        std::cout << std::endl;
    }
}

bool Bank_System::is_account_exist(int account_number)
{
    for (int i = 0; i < bank_accounts.size(); i++)
    {
        if (bank_accounts[i]->get_account_number() == account_number)
            return true;
    }
    return false;
}
