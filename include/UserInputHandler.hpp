#ifndef USERINPUTHANDLER_HPP
#define USERINPUTHANDLER_HPP

#include <limits>
#include "Account.hpp"
#include "InputValidationHandler.hpp"

class UserInputHandler
{
public:
   static void GetMasterInfo(MasterCredential& master);
   static void GetUpperChar(char& input);

   // prevent leading or trailing for all
   static VaultItem GetItemInput();
   static VaultItem GetItemDomain(std::string& itemDomain);
   static VaultItem GetItemUsername(std::string& itemUsername); // validate username down to a string without space and maximum length of 64
   static VaultItem GetItemPassword(std::string& itemPassword); // validate password down to 32
   static VaultItem GetItemDescription(std::string& itemDescription); // no other constraints
   static VaultItem GetItemTag(std::string& itemTag); // no between spaces
};

#endif // !USERINPUTHANDLER_HPP
