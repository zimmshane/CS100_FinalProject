#include <iostream>
#include "../include/Vault.hpp"


int main()
{
   MasterCredential loggedUser{"initialUser", "initialPass"};


   VaultItem item0("johndoe0", "doughy1231", "amazon", "this account has prime", "no tag under this one");
   VaultItem item1("johndoe1", "doughy1232", "amazon", "this account has prime", "");
   VaultItem item2("johndoe2", "doughy1233", "amazon", "this account has prime", "-p");
   VaultItem item3("johndoe3", "doughy1234", "amazon", "this account has prime", "-w");
   VaultItem item4("johndoe4", "doughy1235", "amazon", "this account has prime", "-s");



   Vault vault{ };

   vault.vault[item0.property.domain].push_back(item0);
   vault.vault[item0.property.domain].push_back(item1);
   vault.vault[item0.property.domain].push_back(item2);
   vault.vault[item0.property.domain].push_back(item3);
   vault.vault[item0.property.domain].push_back(item4);


   for (const auto& entry : vault.vault)
   {
      for (auto it = entry.second.begin(); it != entry.second.end(); ++it)
      {
         // honestly assign *it to its type so that it reduces  the amount of dereference calls.
         // should aim to reduce as many new gets as possible, include std::string::size() calls, just assign it to a variable for reference.
         std::cout << (*it).username << " " << (*it).password << " " << (*it).property.domain << " " << (*it).property.description << " " << (*it).property.tag << "\n";
      }
   }

   std::cout << "#: " << vault.vault.size();









   return 0;
}
