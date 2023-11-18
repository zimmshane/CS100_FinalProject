#include "../include/PasswordManager.hpp"
#include "../src/Vault.cpp"
#include "../src/SearchHandler.cpp"

void PasswordManager::Menu_Statement(){
   std::cout<< "Welecome, " << currentUser.username << "\n";
   std::cout << "a - Add an item to vault\n";
   std::cout << "s - Search item from vault\n";
   std::cout << "d - Delete item from vault\n";
   std::cout << "m - Modify item from vault\n";
   std::cout << "l - logout(must sign in again)\n";
   std::cout << "e - exit(auto login will be saved)\n";
}
void PasswordManager::Logout(){
   std::cout << "testing logout\n";
}
void PasswordManager::Exit(){
   std::cout << "testing exit\n";
}
void PasswordManager::Run_CLI_lock()
{
   if(LoginHandler::IsLoginInfoMatchingVault(currentUser))
   {  
      PasswordManager::PrintMasterCredentials();
      //start loading information from vault here
      char userInput;
      Menu_Statement();
      std::cin >> userInput;
      std::cout << "\n";
      char input = std::tolower(userInput, std::locale());
      //example code
      VaultItem item = VaultItem("username" , "password", "domain", "description", "tag");
      SearchHandler search;
      while(input != 'l' || input != 'e'){ 
         if(input == 'a'){ //add item from vault
            userVault.addAccount(item);
         }else if(input == 's'){ //search item from vault
            search.Search("hello");
         }else if(input == 'd'){ //delete item from vault
            userVault.deleteAccount("hello");
         }else if(input == 'm'){ //modify item from vault
            userVault.modifyAccount("hello");
         }else{   //test case if user input an invalid instruction
               std::cout << "Input not recognized, type in a new input: ";
               std::cin >> userInput;
               std::cout << std::endl;
               input = std::tolower(userInput, std::locale());
         }
      }
      if(input == 'l'){ //tests logout
         Logout();
      }
      if(input == 'e'){ //tests exit
         Exit();
      }
   }
}