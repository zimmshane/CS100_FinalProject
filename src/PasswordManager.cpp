#include "../include/PasswordManager.hpp"
#include "../include/Login.hpp"

void PasswordManager::Run_CLI_lock()
{
   Login::GetLoginInfo(currentUser);

}