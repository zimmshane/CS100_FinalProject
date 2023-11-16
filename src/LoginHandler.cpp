#include "../include/LoginHandler.hpp"
#include "../include/FileHandler.hpp"

bool LoginHandler::GetLoginInfo(MasterCredential& master)
{
   char input;

   // TODO: check config file for credentials under [CURRENT]
   for (;;)
   {
      UserInputHandler::GetMasterInfo(master);

      if (!(FileHandler::IsUserVaultExist(master.username)))
      {
         std::cout << "register: \"" << master.username << "\"? (Y/y): ";
         UserInputHandler::GetSingleChar(input);

         if (input == 'Y' || input == 'y')
         {
            RegisterVault(master.username, master.password);
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

void LoginHandler::RegisterVault(const std::string& username, std::string& registerPassword)
{
   if ((username.empty()) &&(registerPassword.empty())) // prevent CTRL+C exit midway of empty password str
   {
      FileHandler::CreateVaultFile(username + ".vault", registerPassword);

      std::cout << "generated \"" << username << ".vault\n";
   }

   return;
}