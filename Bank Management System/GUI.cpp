#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
#include <regex>
using namespace std;

#include "GUI.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Bank_System.h"
#include "Bank_Account.h"

GUI::GUI()
{
    bank_management_system = Bank_System();
}
/**
 * @brief Displays the menu
 */
void GUI::display_menu()
{
    cout << "\t\t........................................." << endl
         << "\t\t| Welcome to the Bank Management System |" << endl
         << "\t\t........................................." << endl
         << "\t\t| 1. Create a bank account              |" << endl
         << "\t\t| 2. Remove bank account                |" << endl
         << "\t\t| 3. Display all bank accounts          |" << endl
         << "\t\t| 4. Find a bank account info           |" << endl
         << "\t\t| 5. Deposit money                      |" << endl
         << "\t\t| 6. Withdraw money                     |" << endl
         << "\t\t| 7. Exit                               |" << endl
         << "\t\t........................................." << endl;
}

/**
 * @brief Prints an error message when the user enters an invalid input
 * @param message Error message
 */
void GUI::print_error_message(string message)
{
    cout << message << endl;
    cout << "Press any key once or twice to continue...";
    cin.clear();
    cin.ignore(100, '\n');
    cin.get();
}

/**
 * @brief Creates a new bank account
 */
void GUI::create_account()
{
    system("cls");
    cout << "-----------------------------------------" << endl
         << "Creating a new bank account..." << endl
         << "-----------------------------------------" << endl
         << "1. Create a savings account" << endl
         << "2. Create a checking account" << endl
         << "3. Back" << endl
         << "-----------------------------------------" << endl
         << "Enter your choice (1-3): ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 3 || cin.fail())
    {
        print_error_message("Invalid choice!!");
        create_account();
        return;
    }
    else if (choice == 1)
    {
        create_savings_account();
    }
    else if (choice == 2)
    {
        create_checking_account();
    }
    else
    {
        cout << "Press any key to continue..." << endl;
        return;
    }
}

/**
 * @brief Creates a new savings account
 */
void GUI::create_savings_account()
{
    cin.ignore();
    string name;
    int account_number, term_in_months;
    float balance, annual_interest_rate;

    system("cls");
    cout << "-----------------------------------------" << endl
         << "Creating a new savings account..." << endl
         << "-----------------------------------------" << endl;

    cout << "Enter account holder name (must be alphabetic only): ";
    getline(cin, name);
    cin.clear();
    regex alphabetic_regex("[a-zA-Z\\s]*");
    if (!regex_match(name, alphabetic_regex) || name == "")
    {
        cout << "Invalid name!! Press any key twice to continue...";
        cin.get();
        create_savings_account();
        return;
    }
    cout << "Enter account number: ";
    cin >> account_number;
    if (bank_management_system.is_account_exist(account_number) || account_number < 0 || cin.fail())
    {
        print_error_message("Account number already exists or invalid account number!!");
        create_savings_account();
        return;
    }

    cout << "Enter balance: ";
    cin >> balance;
    if (balance < 0 || cin.fail())
    {
        print_error_message("Invalid balance!!");
        create_savings_account();
        return;
    }

    cout << "Enter annual interest rate: ";
    cin >> annual_interest_rate;
    if (annual_interest_rate < 0 || cin.fail())
    {
        print_error_message("Invalid annual interest rate!!");
        create_savings_account();
        return;
    }

    cout << "Enter term in months: ";
    cin >> term_in_months;
    if (term_in_months < 0 || cin.fail())
    {
        print_error_message("Invalid term in months!!");
        create_savings_account();
        return;
    }

    Savings_Account *savings_account = new Savings_Account();
    savings_account->set_name(name);
    savings_account->set_account_number(account_number);
    savings_account->deposit(balance);
    savings_account->set_interest_rate(annual_interest_rate);
    savings_account->set_term_in_months(term_in_months);
    bank_management_system.add_bank_account(savings_account);
    cout << "Savings account created successfully!!" << endl;
    cout << "Press any key to continue..." << endl;
}

/**
 * @brief Creates a new checking account
 */
void GUI::create_checking_account()
{
    cin.ignore();
    string name;
    int account_number;
    float balance, monthly_service_charge;

    system("cls");
    cout << "-----------------------------------------" << endl
         << "Creating a new checking account..." << endl
         << "-----------------------------------------" << endl;
    cout << "Enter account holder name (must be alphabetic only): ";
    getline(cin, name);
    cin.clear();
    regex alphabetic_regex("[a-zA-Z\\s]*");
    if (!regex_match(name, alphabetic_regex) || name == " ")
    {
        cout << "Invalid name!! Press any key twice to continue...";
        cin.get();
        create_savings_account();
        return;
    }

    cout << "Enter account number: ";
    cin >> account_number;
    if (bank_management_system.is_account_exist(account_number) || account_number < 0 || cin.fail())
    {
        print_error_message("Account number already exists or invalid account number!!");
        create_checking_account();
        return;
    }
    cout << "Enter balance: ";
    cin >> balance;
    if (balance < 0 || cin.fail())
    {
        print_error_message("Invalid balance!!");
        create_checking_account();
        return;
    }
    cout << "Enter monthly service charge: ";
    cin >> monthly_service_charge;
    if (monthly_service_charge < 0 || cin.fail())
    {
        print_error_message("Invalid monthly service charge!!");
        create_checking_account();
        return;
    }

    Checking_Account *checking_account = new Checking_Account();
    checking_account->set_name(name);
    checking_account->set_account_number(account_number);
    checking_account->deposit(balance);
    checking_account->set_monthly_service_charge(monthly_service_charge);
    bank_management_system.add_bank_account(checking_account);
    cout << "Checking account created successfully!!" << endl;
    cout << "Press any key to continue..." << endl;
}

/**
 * @brief Removes a bank account
 */
void GUI::remove_bank_account()
{
    system("cls");
    cout << "-----------------------------------------" << endl
         << "Removing a bank account..." << endl
         << "-----------------------------------------" << endl
         << "1. Remove by account number" << endl
         << "2. Back" << endl
         << "-----------------------------------------" << endl
         << "Enter your choice (1-2): ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2 || cin.fail())
    {
        print_error_message("Invalid choice!!");
        remove_bank_account();
        return;
    }
    if (choice == 2)
    {
        cout << "Press any key to continue..." << endl;
        return;
    }
    int account_number;
    cout << "Enter account number: ";
    cin >> account_number;
    if (!bank_management_system.is_account_exist(account_number) || cin.fail())
    {
        print_error_message("Account number does not exist or invalid account number!!");
        remove_bank_account();
        return;
    }

    bank_management_system.remove_bank_account(account_number);
    cout << "Bank account removed successfully!!" << endl;
    cout << "Press any key to continue..." << endl;
}

/**
 * @brief Displays all bank accounts information
 */
void GUI::display_all_bank_accounts()
{
    system("cls");
    cout << "-----------------------------------------" << endl
         << "Displaying all bank accounts..." << endl
         << "-----------------------------------------" << endl;
    bank_management_system.display_all_bank_accounts();
    cout << "Press any key to continue..." << endl;
}

/**
 * @brief Displays information of a given bank account
 */
void GUI::display_bank_account()
{
    system("cls");
    cout << "-----------------------------------------" << endl
         << "Displaying a bank account..." << endl
         << "-----------------------------------------" << endl
         << "1. Display by account number" << endl
         << "2. Back" << endl
         << "-----------------------------------------" << endl
         << "Enter your choice (1-2): ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2 || cin.fail())
    {
        print_error_message("Invalid choice!!");
        display_bank_account();
        return;
    }
    if (choice == 2)
    {
        cout << "Press any key to continue..." << endl;
        return;
    }

    int account_number;
    cout << "Enter account number: ";
    cin >> account_number;
    if (!bank_management_system.is_account_exist(account_number) || cin.fail())
    {
        print_error_message("Account number does not exist or invalid account number!!");
        display_bank_account();
        return;
    }

    Bank_Account *bank_account = bank_management_system.get_bank_account(account_number);
    bank_account->display();
    cout << "Press any key to continue..." << endl;
}

/**
 * @brief Deposits money to a given bank account
 */
void GUI::deposit_money()
{
    system("cls");
    cout << "-----------------------------------------" << endl
         << "Depositing money to a bank account..." << endl
         << "-----------------------------------------" << endl
         << "1. Deposit by account number" << endl
         << "2. Back" << endl
         << "-----------------------------------------" << endl
         << "Enter your choice (1-2): ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2 || cin.fail())
    {
        print_error_message("Invalid choice!!");
        deposit_money();
        return;
    }
    if (choice == 2)
    {
        cout << "Press any key to continue..." << endl;
        return;
    }

    int account_number;
    cout << "Enter account number: ";
    cin >> account_number;
    if (!bank_management_system.is_account_exist(account_number) || cin.fail())
    {
        print_error_message("Account number does not exist or invalid account number!!");
        deposit_money();
        return;
    }

    cout << "Enter amount: ";
    float amount;
    cin >> amount;
    if (amount < 0 || cin.fail())
    {
        print_error_message("Invalid amount!!");
        deposit_money();
        return;
    }

    bank_management_system.deposit_money(account_number, amount);
    cout << "Money deposited successfully!!" << endl;
    cout << "Press any key to continue..." << endl;
}

/**
 * @brief Withdraws money from a given bank account
 */
void GUI::withdraw_money()
{
    system("cls");
    cout << "-----------------------------------------" << endl
         << "Withdrawing money from a bank account..." << endl
         << "-----------------------------------------" << endl
         << "1. Withdraw by account number" << endl
         << "2. Back" << endl
         << "-----------------------------------------" << endl
         << "Enter your choice (1-2): ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2 || cin.fail())
    {
        print_error_message("Invalid choice!!");
        withdraw_money();
        return;
    }
    if (choice == 2)
    {
        cout << "Press any key to continue..." << endl;
        return;
    }

    int account_number;
    cout << "Enter account number: ";
    cin >> account_number;
    if (!bank_management_system.is_account_exist(account_number) || cin.fail())
    {
        print_error_message("Account number does not exist or invalid account number!!");
        withdraw_money();
        return;
    }
    cout << "Enter amount: ";
    float amount;
    cin >> amount;
    if (amount < 0 || cin.fail())
    {
        print_error_message("Invalid amount!!");
        withdraw_money();
        return;
    }
    if (amount > bank_management_system.get_bank_account(account_number)->get_balance())
    {
        print_error_message("Not enough money in the account!!");
        withdraw_money();
        return;
    }

    bank_management_system.withdraw_money(account_number, amount);
    cout << "Money withdrawn successfully!!" << endl;
    cout << "Press any key to continue..." << endl;
}

/**
 * @brief Runs the system
 */
void GUI::run()
{
    while (true)
    {
        system("cls");
        display_menu();
        cout << "Enter your choice (1-7): ";
        int choice;
        cin >> choice;
        if (choice < 1 || choice > 7 || cin.fail())
        {
            print_error_message("Invalid choice!!");
            continue;
        }
        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            remove_bank_account();
            break;
        case 3:
            display_all_bank_accounts();
            break;
        case 4:
            display_bank_account();
            break;
        case 5:
            deposit_money();
            break;
        case 6:
            withdraw_money();
            break;
        case 7:
            cout << "Thank you for using our system!!! (= + =)";
            exit(0);
        default:
            print_error_message("Invalid choice!!");
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cin.get();
    }
}