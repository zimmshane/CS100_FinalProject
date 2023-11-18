#include "../include/PasswordManager.hpp"

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
      char userInput;
      Menu_Statement();
      std::cin >> userInput;
      std::cout << "\n";
      char input = std::tolower(userInput, std::locale());
      while(input != 'l' || input != 'e'){
         if(input == 'a'){ //add item from vault

         }else if(input == 's'){ //search item from vault

         }else if(input == 'd'){ //delete item from vault

         }else if(input == 'm'){ //modify item from vault

         }else{   //test case if user input an invalid instruction
               std::cout << "Input not recognized, type in a new input: ";
               std::cin >> userInput;
               std::cout << std::endl;
               input = std::tolower(userInput, std::locale());
            }
      }
   }
}