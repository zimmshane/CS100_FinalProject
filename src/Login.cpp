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
         std::cout << "register " << master.username << " vault (y/n)? : ";
         std::cin >> input;
         std::cin.ignore();

         if (input == 'y' || input == 'Y')
         {
            RegisterVault(master.username, master.password);
            // add break here when register vault is imlpemented
         }
      }
      else
      {
         std::cout << "password: ";
         std::getline(std::cin, master.password);
         break;
      }
   }

   // move to PrintHandler later for debug prints
   std::cout << "==" << master.username << "\n==" << master.password << "\n";

   return;
}

void Login::RegisterVault(const std::string& username, std::string& newPassword)
{

   return;
}