#include "../include/PasswordManager.hpp"
#include "../src/Vault.cpp"
#include "../src/SearchHandler.cpp"

void PasswordManager::Logout(){
   std::cout << "testing logout\n";
   exit(1);
}
void PasswordManager::Exit(){
   std::cout << "testing exit\n";
   exit(1);
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
            /* code */
            std::cout << "ADDED ITEM\n\n" << std::flush;
            break;
         case 'S':
            std::cout << "SEARCHED ITEM\n\n";
            break;
         case 'M':
            std::cout << "MODIFIED ITEM\n\n";
            break;
         case 'D':
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