#include "../include/PasswordManager.hpp"


void PasswordManager::Logout()
{

   return;
}
void PasswordManager::Exit()
{

   return;
}

void PasswordManager::Run_CLI_lock(int argc , char* argv[])
{
   if(LoginHandler::IsLoginInfoMatchingVault(currentUser))
   { // start loading information from vault here
      char mainMenuInput;
      for(;;)
      {
         PrintHandler::PrintMainMenu();
         UserInputHandler::GetUpperChar(mainMenuInput);

         // system("CLS"); // clear screen after receiving input;

         switch (mainMenuInput)
         {
         case 'A':
            userVault.addAccount(UserInputHandler::GetItemInput()); //thanks jeff!
            std::cout << "ADDED ITEM\n\n" << std::flush;
            break;
         case 'S':
            PrintHandler::PrintVault(&userVault); // mostly for testing. IK it isnt search
            std::cout << "SEARCHED ITEM\n\n";
            break;
         case 'M':
            userVault.modifyAccount(UserInputHandler::getStringInput("Search for an account: "));
            std::cout << "MODIFIED ITEM\n\n";
            break;
         case 'D':
           userVault.deleteAccount(UserInputHandler::getStringInput("Search for an account: "));
            std::cout << "DELETED ITEM\n\n";
            break;
         case 'E':
            std::cout << "EXITED VAULT\n\n";
            return;
         case 'L':
            std::cout << "LOGGED OUT\n\n";
            return;
         default:
            std::cout << "INVALID INPUT\n\n";
            break;
         }

      }

   }
   std::cout << "Missed the IF statement";
   return;
}
