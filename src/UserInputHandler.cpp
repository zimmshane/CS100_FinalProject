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