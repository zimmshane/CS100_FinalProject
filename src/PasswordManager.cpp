#include "../include/PasswordManager.hpp"

void PasswordManager::Run_CLI_lock(int argc, char* argv[])
{
   if(LoginHandler::IsLoginInfoMatchingVault(currentUser))
   { // start loading information from vault here

      char mainMenuInput;
      for (;;)
      {
         PrintHandler::PrintMainMenu();
         UserInputHandler::GetUpperChar(mainMenuInput);

         switch (mainMenuInput)
         {
         case 'A':
            /* code */
            std::cout << "ADDED ITEM\n";
            break;
         case 'S':
            std::cout << "SEARCHED ITEM\n";
            break;
         case 'D':
            std::cout << "DELETED ITEM\n";
            break;
         case 'E':
            std::cout << "EXITED VAULT\n";
            break;
         case 'L':
            std::cout << "LOGGED OUT\n";
            break;

         // default:
         //    break;
         }


      }
   }
}