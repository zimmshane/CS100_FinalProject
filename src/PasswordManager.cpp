#include "../include/PasswordManager.hpp"
#include "../src/Vault.cpp"
#include "../src/SearchHandler.cpp"

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
      PrintHandler Menu_Statement;
      SearchHandler search;
      char input;
      //example code
      VaultItem item = VaultItem("username" , "password", "domain", "description", "tag");
      std::cout<< "Welecome, " << currentUser.username << "\n";
      do{
         char userInput;
         Menu_Statement.PrintMenu();
         UserInputHandler::GetSingleChar(userInput);
         input = std::tolower(userInput, std::locale());
         if(input == 'a'){ //add item from vault
            userVault.addAccount(item); 
         }else if(input == 's'){ //search item from vault
            search.Search("hello");
         }else if(input == 'd'){ //delete item from vault
            userVault.deleteAccount("hello");
         }else if(input == 'm'){ //modify item from vault
            userVault.modifyAccount("hello");
         }else if(input == 'l' || input == 'e'){
            break;
         }else{   //test case if user input an invalid instruction
               std::cout << "Input not recognized, type in a new input: ";
               UserInputHandler::GetSingleChar(userInput);
               input = std::tolower(userInput, std::locale());
         }
      }while(input != 'l' || input != 'e');

      if(input == 'l'){ //tests logout
         Logout();
         return;
      }
      if(input == 'e'){ //tests exit
         Exit();
         return;
      }
   }
}
