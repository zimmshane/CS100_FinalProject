#include "../include/UserInputHandler.hpp"

void UserInputHandler::GetMasterInfo(MasterCredential& master)
{
   for (;;)
   {
      std::cout << "><>username: ";
      std::getline(std::cin, master.username);

      if (!(InputValidationHandler::IsMasterUsernameBad(master.username)))
      {
         for (;;)
         {
            std::cout << "><>password: ";
            std::getline(std::cin, master.password);

            if (!(InputValidationHandler::IsMasterPasswordBad(master.password)))
            {
               return;
            }
         }
      }

   }

   return;
}

void UserInputHandler::GetSingleChar(char& inputVariable)
{
   std::cin >> inputVariable;
   std::cin.ignore();

   return;
}