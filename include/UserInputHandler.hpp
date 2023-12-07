#ifndef USERINPUTHANDLER_HPP
#define USERINPUTHANDLER_HPP

#include <limits>
#include "Account.hpp"
#include "InputValidationHandler.hpp"
#include "PasswordQualityHandler.hpp"
#include "PasswordGenerator.hpp"

class UserInputHandler
{
public:
   static void GetMasterInfo(MasterCredential& master);
   static void GetUpperChar(char& input);
   static void GetIndex(size_t& input, const size_t size);

   // prevent leading or trailing for all
   static VaultItem GetItemInput();
   static void GetItemPassword(std::string& itemPassword); // validate password down to 32
   static void GetGenericInput(const std::string& msg, std::string& field);
};

#endif // !USERINPUTHANDLER_HPP
