#ifndef PASSWORDMANAGER_HPP
#define PASSWORDMANAGER_HPP

#include <iostream>
#include "LoginHandler.hpp"
#include "PrintHandler.hpp"
#include "Vault.hpp"

struct Config
{
   //These values are set by FileHandler::ParseConfig()
   // [GENERATE] password generating settings
   int passwordLength;
   int alphaCount;
   int numberCount;
   int symbolCount;
   // [CURRENT] remembered credentials without logout
   MasterCredential rememberedUser;
};

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
   Config config;


   // debug functions
   inline void PrintMasterCredentials() { std::cout << currentUser.username << " | " << currentUser.password << "\n";
                                          std::cout << currentUser.hashed.hashedUsername << " | " << currentUser.hashed.hashedPassword << "\n"; }

};

#endif // !PASSWORDMANAGER_HPP
