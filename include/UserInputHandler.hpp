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
   static void GetIndex(size_t& input);

   // prevent leading or trailing for all
   static VaultItem GetItemInput();
   static void GetItemDomain(std::string& itemDomain);
   static void GetItemUsername(std::string& itemUsername); // validate username down to a string without space and maximum length of 64
   static void GetItemPassword(std::string& itemPassword); // validate password down to 32
   static void GetItemDescription(std::string& itemDescription); // no other constraints
   static void GetItemTag(std::string& itemTag); // no between spaces
   static void GetGenericInput(const std::string& msg, std::string& field);
};

#endif // !USERINPUTHANDLER_HPP
