#ifndef USERINPUTHANDLER_HPP
#define USERINPUTHANDLER_HPP

#include "Account.hpp"
#include <iostream>
#include <sstream>
#include "InputValidationHandler.hpp"

class UserInputHandler
{
public:
   static void GetMasterInfo(MasterCredential& master);
   static void GetSingleChar(char& inputVariable);
};

#endif // !USERINPUTHANDLER_HPP
