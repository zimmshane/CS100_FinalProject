#include "../include/UserInputHandler.hpp"

void UserInputHandler::GetMasterInfo(MasterCredential& master)
{
   for (;;)
   {
      std::cout << "><>username: ";
      std::getline(std::cin, master.username);

      if (InputValidationHandler::IsUsernameGood(master.username))
      {
         for (;;)
         {
            std::cout << "><>password: ";
            std::getline(std::cin, master.password);

            if (InputValidationHandler::IsPasswordGood(master.password))
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

void UserInputHandler::GetIndex(size_t& input)
{
   std::cin >> input;

   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   return;
}

VaultItem UserInputHandler::GetItemInput()
{
   VaultItem newItem;

   GetGenericInput("><>domain: ", newItem.property.domain);
   GetGenericInput("><>username: ", newItem.username);

   GetItemPassword(newItem.password);

   GetGenericInput("><>description: ", newItem.property.description);
   GetGenericInput("><>tag: ", newItem.property.tag);

   return newItem;
}

void UserInputHandler::GetItemPassword(std::string& itemPassword)
{
   std::string oldPassword = itemPassword;
   for (;;)
   {
      std::cout << "><>password: ";
      std::getline(std::cin, itemPassword);
      if (itemPassword == "~~")
      {
         itemPassword = oldPassword;
         return;
      }
      else if (!(InputValidationHandler::IsContainWhiteSpaceEnds(itemPassword)) && (itemPassword.size() != 0) && PasswordQualityHandler::IsPasswordStrong(itemPassword))
      {
         return;
      }

   }
}

void UserInputHandler::GetGenericInput(const std::string& msg, std::string& inputStrField)
{
   std::string oldString = inputStrField;

   for (;;)
   {
      std::cout << msg;
      std::getline(std::cin, inputStrField);

      if ((inputStrField == "~~") && !(oldString.size() == 0)) // sentinel value for retaining old input if old input isn't empty
      {
         inputStrField = oldString;
         return;
      }
      else if (!(InputValidationHandler::IsContainWhiteSpaceEnds(inputStrField)) && !(inputStrField.size() == 0))
      {
         return;
      }

   }
}
