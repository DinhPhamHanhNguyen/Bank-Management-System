#include "Bank_Account.h"
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

/**
 * @brief Savings Account class. This class represents a savings account, which is a type of bank account.
 * This class is derived from Bank_Account class
 * @param annual_interest_rate Annual interest rate
 * @param duration_in_month Duration of saving money in months
 */
class Savings_Account : public Bank_Account
{
private:
    float annual_interest_rate;
    int duration_in_month;

public:
    Savings_Account();

    /**
     * @brief Sets the annual interest rate
     */
    void set_interest_rate(float interest_rate);

    /**
     * @brief Sets the duration of saving money in months
     */
    void set_term_in_months(int term_in_months);

    /**
     * @brief Displays account information
     */
    void display();

private:
    /**
     * @brief Calculates the monthly interest earn
     * @return Monthly interest earn
     */
    float get_monthly_interest_earn();

    /**
     * @brief Calculates the total interest earn after term
     * @return Total interest earn after term
     */
    float get_interest_earn();

    /**
     * @brief Calculates the total balance after term
     * @return Total balance after term
     */
    float get_total_balance();
};
#endif // SAVINGS_ACCOUNT_H