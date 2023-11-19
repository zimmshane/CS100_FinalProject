#ifndef PASSWORDMANAGER_HPP
#define PASSWORDMANAGER_HPP

#include <iostream>
#include "Vault.hpp"
#include "LoginHandler.hpp"
#include "Account.hpp"
class Vault;
class LoginHandler;
class Account;
class VaultItem;

class PasswordManager
{
public:
   PasswordManager() { }
   ~PasswordManager() { }
   void Run_CLI_lock(int argc, char* argv[]);

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
