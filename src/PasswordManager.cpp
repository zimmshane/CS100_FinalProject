#include "../include/PasswordManager.hpp"
#include "../include/LoginHandler.hpp"

void PasswordManager::Run_CLI_lock(int argc, char* argv[])
{
   LoginHandler::GetLoginInfo(currentUser);

         PrintMasterCredentials();
}