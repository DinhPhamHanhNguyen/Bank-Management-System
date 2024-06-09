#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "Bank_Account.h"
/**
 * @brief Checking Account class. This class represents a checking account and
 * is derived from Bank_Account class
 * @param monthly_service_charge Monthly service charge to maintain the account
 */
class Checking_Account : public Bank_Account
{
private:
    float monthly_service_charge;

public:
    Checking_Account();

    /**
     * @brief Sets the monthly service charge
     */
    void set_monthly_service_charge(float monthly_service_charge);

    /**
     * @brief Displays account information
     */
    void display();

private:
    /**
     * @brief Calculates the net balance after service charge
     * @return Net balance after service charge
     */
    float estimate_total_balance();
};
#endif // CHECKING_ACCOUNT_H