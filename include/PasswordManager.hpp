#ifndef PASSWORDMANAGER_HPP
#define PASSWORDMANAGER_HPP

#include <iostream>
#include "Vault.hpp"
#include "LoginHandler.hpp"
#include "SearchHandler.hpp"
#include "UserInputHandler.hpp"

class PasswordManager
{
public:
   PasswordManager() { }
   ~PasswordManager() { }
   void Run_CLI_lock();
   void Menu_Statement();

   MasterCredential currentUser;
   Vault userVault;
   Vault encryptedVault;

   struct Config
   {
      // [GENERATE] password generating settings


      // [CURRENT] remembered credentials without logout
      MasterCredential rememberedUser;
   };

   Config config;
   void Logout();
   void Exit();
   // debug functions
   inline void PrintMasterCredentials() { std::cout << currentUser.username << " | " << currentUser.password << "\n"; }

};

#endif // !PASSWORDMANAGER_HPP
