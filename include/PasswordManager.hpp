#ifndef PASSWORDMANAGER_HPP
#define PASSWORDMANAGER_HPP

#include "Vault.hpp"

class PasswordManager
{
public:
   PasswordManager() { }
   ~PasswordManager() { }
   void Run_CLI_lock();

   MasterCredential currentUser;
   Vault userVault;
   Vault encryptedVault;

   struct Config
   {
      // [GENERATE] password generating settings


      // [CURRENT] remembered credentials without logout
      Account rememberedUser;
      std::string cipherKEY;
   };

   Config config;
};

#endif // !PASSWORDMANAGER_HPP
