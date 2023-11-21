#include "../include/UserInputHandler.hpp"

void UserInputHandler::GetMasterInfo(MasterCredential& master)
{
   for (;;)
   {
      std::cout << "><>username: ";
      std::getline(std::cin, master.username);

      if (InputValidationHandler::IsMasterUsernameGood(master.username))
      {
         for (;;)
         {
            std::cout << "><>password: ";
            std::getline(std::cin, master.password);

            if (InputValidationHandler::IsMasterPasswordGood(master.password))
            {
               return;
            }
         }
      }

   }

   return;
}

// reusable for later main menu inputs, ignores case sensitivty normalized with toupper
void UserInputHandler::GetUpperChar(char& input)
{
   std::cin >> input;
   input = static_cast<char>(toupper(input));

   // ignore remaining buffered input
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   return;
}

VaultItem UserInputHandler::GetItemInput()
{
   VaultItem newItem;

   std::cout << "><>domain: ";
   GetExcludeWhiteSpaceInput(newItem.property.domain);

   std::cout << "><>username: ";
   GetExcludeWhiteSpaceInput(newItem.username);

   std::cout << "><>password: ";
   GetItemPassword(newItem.password);

   std::cout << "><>description: ";
   GetExcludeWhiteSpaceInput(newItem.property.description);

   std::cout << "><>tag: ";
   GetExcludeWhiteSpaceInput(newItem.property.tag);

   return newItem;
}

void UserInputHandler::GetItemPassword(std::string& itemPassword)
{
   for (;;)
   {
      std::getline(std::cin, itemPassword);

      if (!(InputValidationHandler::IsEndsWhiteSpace(itemPassword)) && !(itemPassword.size() == 0) && PasswordQualityHandler::StrengthChecker(itemPassword))
      {
         return;
      }

      std::cout << "invalid, check for white space on ends, or quality of password\n";
   }
}

void UserInputHandler::GetExcludeWhiteSpaceInput(std::string& itemField)
{
   for (;;)
   {
      std::cout << "><>: ";
      std::getline(std::cin, itemField);

      if (!(InputValidationHandler::IsEndsWhiteSpace(itemField)) && !(itemField.size() == 0))
      {
         return;
      }

      std::cout << "contains leading or trailing whitespace\n";
   }
}
