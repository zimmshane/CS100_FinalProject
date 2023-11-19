#include "../include/PrintHandler.hpp"

void PrintHandler::PrintVault(const Vault& vault)
{
   for (auto& entry : vault.vault)
   {
      std::cout << "========" << entry.first << "========\n";
      // sort vector
      // std::sort(entry.second.begin(), entry.second.end());

      for (auto it = entry.second.begin(); it != entry.second.end(); ++it)
      {
         // honestly assign *it to its type so that it reduces  the amount of dereference calls.
         // should aim to reduce as many new gets as possible, include std::string::size() calls, just assign it to a variable for reference.
         std::cout << (*it).username << " " << (*it).password << " " << (*it).property.domain << " " << (*it).property.description << " " << (*it).property.tag << "\n";
      }
   }
}
void PrintHandler::PrintMenu(){
   std::cout << "a - Add an item to vault\n";
   std::cout << "s - Search item from vault\n";
   std::cout << "d - Delete item from vault\n";
   std::cout << "m - Modify item from vault\n";
   std::cout << "l - logout(must sign in again)\n";
   std::cout << "e - exit(auto login will be saved)\n";
}