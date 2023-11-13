#include "../include/Login.hpp"
#include "../include/FileHandler.hpp"

void Login::GetLoginInfo(MasterCredential& info)
{
   // TODO: check config file for credentials under [CURRENT]
   std::string username, password;
   std::cout << "Username: ";
   std::cin >> info.username;
   FileHandler::DoesUserVaultExist(username);





   // std::cout << "Password: ";
   // std::cin >> password;


   // info.username = username;
   // info.password = password;
}