#include "../include/PrintHandler.hpp"
#include "../include/Vault.hpp"
#include "../include/Account.hpp"

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
void PrintHandler::printVector(const std::vector<VaultItem>& list){
   int count = 1;
   for (auto it = list.begin(); it != list.end(); ++it){
      std::cout << count << ". " << (*it).property.domain << " , " <<  (*it).username << " \n"; //prints items in vector w/ index count
      ++count;
   }
}
void PrintHandler::printVaultItem(const VaultItem& vitem){
   std::cout << std::endl << vitem.property.domain << " , " << vitem.username << " , " << vitem.password << " , "<< vitem.property.description << " , " << vitem.property.tag << std::endl;

void PrintHandler::PrintMainMenu()
{
   std::cout << "(A)dd\n"
      << "(S)earch \n"
      << "(D)elete\n"
      << "(M)odify\n"
      << "(L)ogout\n"
      << "(E)xit\n"
      << "><>choice: ";

   return;
}