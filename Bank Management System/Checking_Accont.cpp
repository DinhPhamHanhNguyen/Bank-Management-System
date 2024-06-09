#include "Checking_Account.h"
#include <iostream>

Checking_Account::Checking_Account()
{
    monthly_service_charge = 0.0;
}

void Checking_Account::set_monthly_service_charge(float monthly_service_charge)
{
    this->monthly_service_charge = monthly_service_charge;
}

void Checking_Account::display()
{
    cout << "Account type: Checking Account" << endl;
    Bank_Account::display();
    cout << "Monthly service charge: " << monthly_service_charge << endl;
    cout << "Net balance after service charge: " << estimate_total_balance() << endl;
}

float Checking_Account::estimate_total_balance()
{
    return balance - monthly_service_charge;
}
