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
   static std::string getStringInput(const std::string& message);
   static void GetUpperChar(char& input);
   static VaultItem GetItemInput();
};

#endif // !USERINPUTHANDLER_HPP
