
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

// reusable for later main menu inputs
void UserInputHandler::GetSingleChar(char& input)
{
   std::cin >> input;
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   return;
}
void UserInputHandler::getStringInput(const std::string& msg, std::string& input){
   std::cout << msg;
   getline(std::cin,input); 
   //TODO input validation
}

