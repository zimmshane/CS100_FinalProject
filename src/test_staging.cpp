#include <iostream>
#include "../include/Vault.hpp"


int main()
{
   MasterCredentials loggedUser{"initialUser", "initialPass"};


   VaultItem item0("johndoe0", "doughy1231", "amazon", "this account has prime", "empt string means no tag");
   VaultItem item1("johndoe1", "doughy1232", "amazon", "this account has prime", "empt string means no tag");
   VaultItem item2("johndoe2", "doughy1233", "amazon", "this account has prime", "empt string means no tag");
   VaultItem item3("johndoe3", "doughy1234", "amazon", "this account has prime", "empt string means no tag");
   VaultItem item4("johndoe4", "doughy1235", "amazon", "this account has prime", "empt string means no tag");



   Vault vault{ };

   vault.vault[item0.properties.domain].push_back(item0);
   vault.vault[item0.properties.domain].push_back(item1);
   vault.vault[item0.properties.domain].push_back(item2);
   vault.vault[item0.properties.domain].push_back(item3);
   vault.vault[item0.properties.domain].push_back(item4);


   for (const auto& entry : vault.vault)
   {
      for (auto it = entry.second.begin(); it != entry.second.end(); ++it)
      {
         // honestly assign *it to its type so that it reduces  the amount of dereference calls.
         // should aim to reduce as many new gets as possible, include std::string::size() calls, just assign it to a variable for reference.
         std::cout << (*it).username << " " << (*it).password << " " << (*it).properties.domain << " " << (*it).properties.description << " " << (*it).properties.tag << "\n";
      }
   }

   std::cout << "#: " << vault.vault.size();









   return 0;
}
