#ifndef PASSWORDMANAGER_HPP
#define PASSWORDMANAGER_HPP

#include <iostream>
#include "LoginHandler.hpp"
#include "PrintHandler.hpp"
#include "Vault.hpp"


class PasswordManager
{
public:
   PasswordManager() { }
   ~PasswordManager() { }
   void Run_CLI_lock(int argc , char* argv[]);

   // config cache
   void LogoutVault(); // empty [CURRENT]
   void ExitVault(); // save under [CURRENT]

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


   // debug functions
   inline void PrintMasterCredentials() { std::cout << currentUser.username << " | " << currentUser.password << "\n"; }

};

#endif // !PASSWORDMANAGER_HPP
