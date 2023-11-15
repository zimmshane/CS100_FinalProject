#include "../include/LoginHandler.hpp"
#include "../include/FileHandler.hpp"

void LoginHandler::GetLoginInfo(MasterCredential& master)
{
   // TODO: check config file for credentials under [CURRENT]
   UserInputHandler::GetMasterInfo(master);



   // while (true)
   // {
   //    std::cout << "username: ";
   //    std::getline(std::cin, master.username); // verify no bad windows characters, make sure no period before .vault -> ..vault

   //    if (!(FileHandler::DoesUserVaultExist(master.username))) // if dne, register the vault
   //    {
   //       std::cout << "register: \"" << master.username << "\"? (Y/y): ";
   //       std::cin >> input; // make sure input doesn't carry over to next buffer
   //       std::cin.ignore();

   //       if (input == 'Y' || input == 'y')
   //       {
   //          RegisterVault(master.username, master.password);
   //          // break; // if no break, dont pass password to force relogin after register
   //       }
   //    }
   //    else // vault exists
   //    {
   //       std::cout << "password: ";
   //       std::getline(std::cin, master.password);
   //       break;
   //    }
   // }

   return;
}

void LoginHandler::RegisterVault(const std::string& username, std::string& registerPassword)
{
   std::cout << "password: ";
   std::getline(std::cin, registerPassword);

   if (!(registerPassword == "")) // prevent CTRL+C exit midway of empty password str
   {
      FileHandler::CreateVaultFile(username + ".vault", registerPassword);
   }

   return;
}