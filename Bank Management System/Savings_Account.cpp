#include "Savings_Account.h"
#include <iostream>

Savings_Account::Savings_Account()
{
    annual_interest_rate = 0.0;
    duration_in_month = 0;
}

void Savings_Account::set_interest_rate(float interest_rate)
{
    this->annual_interest_rate = interest_rate;
}

void Savings_Account::set_term_in_months(int term_in_months)
{
    this->duration_in_month = term_in_months;
}

void Savings_Account::display()
{
    cout << "Account type: Savings Account" << endl;
    Bank_Account::display();
    cout << "Interest rate: " << annual_interest_rate << endl;
    cout << "Term in months: " << duration_in_month << endl;
    cout << "Estimated monthly interest earn: " << get_monthly_interest_earn() << endl;
    cout << "Estimated interest earn after term: " << get_interest_earn() << endl;
    cout << "Estimated balance after term: " << get_total_balance() << endl;
}

float Savings_Account::get_monthly_interest_earn()
{
    return balance * annual_interest_rate / 12;
}

float Savings_Account::get_interest_earn()
{
    return balance * annual_interest_rate * duration_in_month / 12;
}

float Savings_Account::get_total_balance()
{
    return balance + get_interest_earn();
}
