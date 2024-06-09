#include "Bank_Account.h"
#include <vector>

#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

using namespace std;

/**
 * @brief This class represents a bank management system
 * @param bank_accounts contains all the bank accounts of the system
 */
class Bank_System
{
private:
    vector<Bank_Account *> bank_accounts;

public:
    Bank_System();
    /**
     * @brief Creates a new bank account and registers it to the system
     */
    void add_bank_account(Bank_Account *bank_account);

    /**
     * @brief Removes a bank account from the system
     */
    void remove_bank_account(int account_number);

    /**
     * @brief Deposits money to a bank account
     * @param bank_account Bank account to deposit money
     * @param amount Amount to be deposited
     */
    void deposit_money(int account_number, float amount);

    /**
     * @brief Withdraws money from a bank account
     * @param bank_account Bank account to withdraw money
     * @param amount Amount to be withdrawn
     */
    void withdraw_money(int account_number, float amount);

    /**
     * @brief Gets a bank account from the system
     * @param account_number Account number of the bank account
     * @return Bank account
     */
    Bank_Account *get_bank_account(int account_number);

    /**
     * @brief Displays all bank accounts information
     */
    void display_all_bank_accounts();

    /**
     * @brief Checks if a bank account exists in the system
     * @param account_number Account number of the bank account
     * @return True if the bank account exists, false otherwise
     */
    bool is_account_exist(int account_number);
};
#endif // BANK_SYSTEM_H