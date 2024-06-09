#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <string>
using namespace std;

/**
 * @brief Bank Account class. This class is an abstract class to represent a bank account
 * @param account_holder_name Name of the account holder
 * @param account_number Account number
 * @param balance Balance of the account
 */
class Bank_Account
{
protected:
    string account_holder_name;
    int account_number;
    float balance;

public:
    /**
     * @brief Constructor
     */
    Bank_Account();

    /**
     * @brief Deposits money to the bank account
     * @param balance Amount to be deposited
     */
    virtual void deposit(float balance);

    /**
     * @brief Withdraws money from the bank account
     * @param balance Amount to be withdrawn
     */
    virtual void withdraw(float balance);

    /**
     * @brief Sets the name of the account holder
     * @param name Name of the account holder
     */
    void set_name(string name);

    /**
     * @brief Sets the account number
     * @param account_number Account number
     */
    void set_account_number(int account_number);

    /**
     * @brief Gets the name of the account holder
     * @return Account number
     */
    int get_account_number();

    /**
     * @brief Gets the balance of the account
     * @return Balance of the account
     */
    float get_balance();

    /**
     * @brief Displays account information
     */
    virtual void display();
};
#endif // BANK_ACCOUNT_H