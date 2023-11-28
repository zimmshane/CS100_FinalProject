#include "../include/PrintHandler.hpp"

void PrintHandler::PrintMainMenu()
{
   std::cout << "(A)dd\n"
            << "(S)earch \n"
            << "(M)odify\n"
            << "(D)elete\n"
            << "(E)xit\n"
            << "(L)ogout\n"
            << "(P)rint vault\n"
            << "><>choice: ";

   return;
}

void PrintHandler::PrintItem(const VaultItem& item)
{
   std::cout << "domain: " << item.property.domain << "\n" // remove this line in prod
            << "username: " << item.username << "\n"
            << "password: " << item.password << "\n"
            << "description: " << item.property.description << "\n"
            << "tag: " << item.property.tag << "\n\n";
}

void PrintHandler::PrintVault(const Vault& vault)
{
   for (auto& entry : vault.vaultContainer)
   {
      std::cout << "========" << entry.first << "========\n";

      // sort vector for std::map sorted key, so sort vector as well for organization
      // std::sort(entry.second.begin(), entry.second.end());

      for (auto it = entry.second.begin(); it != entry.second.end(); ++it)
      {
         // honestly assign *it to its type so that it reduces  the amount of dereference calls.
         // should aim to reduce as many new gets as possible, include std::string::size() calls, just assign it to a variable for reference.
         std::cout << "domain: " << (*it).property.domain << "\n" // remove this line in prod
                  << "username: " << (*it).username << "\n"
                  << "password: " << (*it).password << "\n"
                  << "description: " << (*it).property.description << "\n"
                  << "tag: " << (*it).property.tag << "\n\n";
      }
   }
}
