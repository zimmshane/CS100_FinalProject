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