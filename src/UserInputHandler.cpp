#include "../include/UserInputHandler.hpp"

void UserInputHandler::GetMasterInfo(MasterCredential& master)
{
   for (;;)
   {
      std::cout << "><>username: ";
      std::getline(std::cin, master.username);

      if (InputValidationHandler::IsUsernameBad(master.username))
      {
         std::cout << "><>username: ";
         std::getline(std::cin, master.username);
      }

   }
}