#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
#include <regex>

#include "Bank_Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Bank_System.h"
#include "GUI.h"
using namespace std;

int main()
{
    GUI gui;
    gui.run();
    return 0;
}