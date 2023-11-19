#include "../include/PasswordManager.hpp"
#include "../src/Vault.cpp"
#include "../src/SearchHandler.cpp"

void PasswordManager::Logout(){
   std::cout << "testing logout\n";
   exit(1);
}
void PasswordManager::Exit(){
   std::cout << "testing exit\n";
   exit(1);
}

void PasswordManager::Run_CLI_lock(int argc , char* argv[])
{
   if(LoginHandler::IsLoginInfoMatchingVault(currentUser))
   {  
      PasswordManager::PrintMasterCredentials();
      char userInput;
      char input;
      PrintHandler Menu_Statement;
      SearchHandler search;
      bool runUntilQuit = true;
      while(runUntilQuit){
         Menu_Statement.PrintMenu();
         UserInputHandler::GetSingleChar(userInput);
         input = std::tolower(userInput, std::locale());
         switch(input){
            case 'a':
               std::cout << "Added item\n";
               break;
            case 's':
               search.Search("hello");
               break;
           case 'd':
               userVault.deleteAccount("hello");
               break;
            case 'm':
               userVault.modifyAccount("hello");
               break;
            case 'e':
               Exit();
               break;
            case 'l':
               Logout();
               break;
            default:
               std::cout<<"Invalud Input\n";
               break;
         }
      }
   }
}