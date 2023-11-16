#ifndef USERINPUTHANDLER_HPP
#define USERINPUTHANDLER_HPP

#include "InputValidationHandler.hpp"
#include "Account.hpp"

class UserInputHandler
{
public:
   static void GetMasterInfo(MasterCredential& master);
   static void GetSingleChar(char& inputVariable);
};

#endif // !USERINPUTHANDLER_HPP
