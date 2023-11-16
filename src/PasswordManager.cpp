#include "../include/PasswordManager.hpp"

void PasswordManager::Run_CLI_lock(int argc, char* argv[])
{
   if(LoginHandler::GetLoginInfo(currentUser))
   { // start loading information from vault here
      PasswordManager::PrintMasterCredentials();
   }
}