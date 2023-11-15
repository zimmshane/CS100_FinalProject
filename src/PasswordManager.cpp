#include "../include/PasswordManager.hpp"
#include "../include/Login.hpp"

void PasswordManager::Run_CLI_lock(int argc, char* argv[])
{
   Login::GetLoginInfo(currentUser);

         PrintMasterCredentials();
}