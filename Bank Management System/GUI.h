#ifndef GUI_H
#define GUI_H

#include "Bank_System.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Bank_System.h"
#include "Bank_Account.h"

#include <string>

using namespace std;

/**
 * @brief GUI class. This is the user interface of the system to interact with the user.
 * @param bank_management_system Bank management system
 */
class GUI
{
private:
    Bank_System bank_management_system;

public:
    GUI();
    /**
     * @brief Displays the menu
     */
    void display_menu();

    /**
     * @brief Prints an error message when the user enters an invalid input
     * @param message Error message
     */
    void print_error_message(string message);

    /**
     * @brief Creates a new bank account
     */
    void create_account();

    /**
     * @brief Creates a new savings account
     */
    void create_savings_account();

    /**
     * @brief Creates a new checking account
     */
    void create_checking_account();

    /**
     * @brief Removes a bank account
     */
    void remove_bank_account();

    /**
     * @brief Displays all bank accounts information
     */
    void display_all_bank_accounts();

    /**
     * @brief Displays information of a given bank account
     */
    void display_bank_account();

    /**
     * @brief Deposits money to a given bank account
     */
    void deposit_money();

    /**
     * @brief Withdraws money from a given bank account
     */
    void withdraw_money();

    /**
     * @brief Runs the system
     */
    void run();
};
#endif // GUI_H