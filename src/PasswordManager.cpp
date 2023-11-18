#include "../include/PasswordManager.hpp"
#include <string>

void PasswordManager::Menu_Statement(){
   std::cout<< "Welecome, " << currentUser.username << "\n";
   std::cout << "a - Add an item to vault\n";
   std::cout << "s - Search item from vault\n";
   std::cout << "d - Delete item from vault\n";
   std::cout << "m - Modify item from vault\n";
   std::cout << "l - logout(must sign in again)\n";
   std::cout << "e - exit(auto login will be saved)\n";
}
void PasswordManager::Run_CLI_lock()
{
   if(LoginHandler::IsLoginInfoMatchingVault(currentUser))
   {  
   PasswordManager::PrintMasterCredentials();
   //start loading information from vault here
  // char userInput;
  // std::cout<< "Welecome, " << currentUser.username << endl;

   

   }
}