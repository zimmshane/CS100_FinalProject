#include "../include/PasswordManager.hpp"
#include "../src/Vault.cpp"
#include "../src/SearchHandler.cpp"

void PasswordManager::LogoutVault()
{
   // write to file first FileHandler::
   FileHandler::WriteVaultToFile(currentUser, userVault.vaultContainer);

   // rewrite config file with currentUser login information

   return;
}

void PasswordManager::ExitVault()
{
   // write to file first FileHandler::
   FileHandler::WriteVaultToFile(currentUser, userVault.vaultContainer);

   // donothing?

   return;
}

void PasswordManager::Run_CLI_lock(int argc , char* argv[])
{
   if(LoginHandler::IsLoginInfoMatchingVault(currentUser))
   {
      // start loading information from vault here

      FileHandler::LoadVaultFile(currentUser.username, userVault);

      char mainMenuInput;
      std::string menuStringInput;

      for (;;)
      {
         PrintHandler::PrintMainMenu();
         UserInputHandler::GetUpperChar(mainMenuInput);

         // system("CLS"); // clear screen after receiving input;

         switch (mainMenuInput)
         {
         case 'A':
            /* code */
            userVault.AddItem(UserInputHandler::GetItemInput());
            std::cout << "ADDED ITEM\n\n";
            break;
         case 'S':
            std::cout << "\n\nSEARCHED ITEM\n\n"; // get line, parse arguments, different overload based on # of arguments
            break;
         case 'M':
            UserInputHandler::GetGenericInput("><>username: ", menuStringInput);
            userVault.ModifyItem(menuStringInput);
            std::cout << "\n\nMODIFIED ITEM\n\n";
            break;
         case 'D':
            UserInputHandler::GetGenericInput("><>username: ", menuStringInput);
            userVault.DeleteItem(menuStringInput);
            std::cout << "\n\nDELETED ITEM\n\n";
            break;
         case 'E':
            std::cout << "\n\nEXITED VAULT\n\n";
            ExitVault();
            return;
         case 'L':
            std::cout << "\n\nLOGGED OUT\n\n";
            LogoutVault();
            return;
         case 'P':
            PrintHandler::PrintVault(userVault);
            std::cout << "\n\nPRINTED VAULT\n\n";
            break;
         default:
            std::cout << "\n\nINVALID INPUT\n\n";
            break;
         }

      }

   }

   return;
}