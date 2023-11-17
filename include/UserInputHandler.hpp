#ifndef USERINPUTHANDLER_HPP
#define USERINPUTHANDLER_HPP

#include <limits>
#include "Account.hpp"
#include "InputValidationHandler.hpp"

class UserInputHandler
{
public:
   static void GetMasterInfo(MasterCredential& master);
   static void GetSingleChar(char& inputVariable);
};

#endif // !USERINPUTHANDLER_HPP
