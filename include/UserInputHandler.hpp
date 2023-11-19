#ifndef USERINPUTHANDLER_HPP
#define USERINPUTHANDLER_HPP

#include <limits>
#include <string>
#include "Account.hpp"
#include "InputValidationHandler.hpp"

class UserInputHandler
{
public:
   static void GetMasterInfo(MasterCredential& master);
   static void GetSingleChar(char& inputVariable);
   static void getStringInput(const std::string& message,std::string& input);
   static void GetUpperChar(char& input);
};

#endif // !USERINPUTHANDLER_HPP
