#include "../include/LoginHandler.hpp"
#include "../include/FileHandler.hpp"

void LoginHandler::GetLoginInfo(MasterCredential& master)
{
   char input;

   // TODO: check config file for credentials under [CURRENT]
   for (;;)
   {
      UserInputHandler::GetMasterInfo(master);

      if (!(FileHandler::DoesUserVaultExist(master.username)))
      {
         std::cout << "register: \"" << master.username << "\"? (Y/y): ";
         UserInputHandler::GetSingleChar(input);

         if (input == 'Y' || input == 'y')
         {
            RegisterVault(master.username, master.password);
         }
      }
   }

   return;
}

void LoginHandler::RegisterVault(const std::string& username, std::string& registerPassword)
{
   if (registerPassword.size() != 0) // prevent CTRL+C exit midway of empty password str
   {
      FileHandler::CreateVaultFile(username + ".vault", registerPassword);

      std::cout << "created" << username << ".vault\n";
   }

   return;
}