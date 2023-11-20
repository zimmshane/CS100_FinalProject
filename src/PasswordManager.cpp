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
      for (;;)
      {
         PrintHandler::PrintMainMenu();
         UserInputHandler::GetUpperChar(mainMenuInput);

         // system("CLS"); // clear screen after receiving input;

         switch (mainMenuInput)
         {
         case 'A':
            //TODO: addAccount takes a VaultItem input, how do we we want to get this info?
            //userVault->addAccount(VAULTITEM)
            std::cout << "ADDED ITEM\n\n" << std::flush;
            break;
         case 'S':
            std::cout << "SEARCHED ITEM\n\n";
            break;
         case 'M':
            std::string input;
            UserInputHandler::getStringInput("Enter an domain or account: ",input);
            userVault->modifyAccount(input);
            std::cout << "MODIFIED ITEM\n\n";
            break;
         case 'D':
            std::string input;
            UserInputHandler::getStringInput("Enter an domain or account: ",input);
            userVault->deleteAccount(input);
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

   return;
}
