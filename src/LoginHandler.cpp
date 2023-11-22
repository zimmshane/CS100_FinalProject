#include "../include/LoginHandler.hpp"

bool LoginHandler::IsLoginInfoMatchingVault(MasterCredential& master)
{
   // TODO: check config file for credentials under [CURRENT])

   char registerConfirmation;

   for (;;)
   {
      UserInputHandler::GetMasterInfo(master);

      // force relogin after register to ensure user input the right information they wanted
      if (!(FileHandler::IsUserVaultExist(master.username)))
      {
         std::cout << "><>register: \"" << master.username << "\"? (Y/y): ";
         UserInputHandler::GetUpperChar(registerConfirmation);

         if (registerConfirmation == 'Y')
         {
            RegisterVault(master);
         }
      }
      else if (FileHandler::IsVaultPasswordMatch(master))
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

      std::cout << "\tgenerated \"" << master.username << ".vault\n";
   }

   return;
}