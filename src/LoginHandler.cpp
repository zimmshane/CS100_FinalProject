#include "../include/LoginHandler.hpp"

bool LoginHandler::GetLoginInfo(MasterCredential& master)
{
   char input;

   // TODO: check config file for credentials under [CURRENT]
   // force relogin after register to ensure user input the right information they wanted

   for (;;)
   {
      UserInputHandler::GetMasterInfo(master);

      if (!(FileHandler::IsUserVaultExist(master.username)))
      {
         std::cout << master.username.size() << "\n\n";
         std::cout << "register: \"" << master.username << "\"? (Y/y): ";
         UserInputHandler::GetSingleChar(input);

         if (input == 'Y' || input == 'y')
         {
            RegisterVault(master);
         }
      }

      // check first line of .vault to match password, register naturally falls here, no need to relogin
      if (FileHandler::IsVaultPasswordMatch(master))
      {
         return true;
      }
   }

   return false;
}

void LoginHandler::RegisterVault(const MasterCredential& master)
{
   if (!((master.username.empty()) && (master.password.empty()))) // prevent CTRL+C exit midway of empty password str
   {
      FileHandler::CreateVaultFile(master);

      std::cout << "generated \"" << master.username << ".vault\n";
   }

   return;
}