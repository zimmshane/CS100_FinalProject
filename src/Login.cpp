#include "../include/Login.hpp"
#include "../include/FileHandler.hpp"

void Login::GetLoginInfo(MasterCredential& master)
{
   // TODO: check config file for credentials under [CURRENT]
   char input;

   while (true)
   {
      std::cout << "username: ";
      std::getline(std::cin, master.username);

      if (!(FileHandler::DoesUserVaultExist(master.username))) // if dne, register the vault
      {
         std::cout << "register: \"" << master.username << "\"? (Y/y): ";
         std::cin >> input; // make sure input doesn't carry over to next buffer
         std::cin.ignore();

         if (input == 'Y' || input == 'y')
         {
            RegisterVault(master.username, master.password);
            // break; // if no break, dont pass password to force relogin after register
         }
      }
      else // vault exists
      {
         std::cout << "password: ";
         std::getline(std::cin, master.password);
         break;
      }
   }

   return;
}

void Login::RegisterVault(const std::string& username, std::string& registerPassword)
{
   std::cout << "password: ";
   std::getline(std::cin, registerPassword);

   if (registerPassword.empty()) // prevent CTRL+C exit midway of empty password str
   {
      FileHandler::CreateVaultFile(username + ".vault", registerPassword);
   }

   std::cout << "><>vault sucessfully registered\n";

   return;
}