#include <iostream>
#include "../include/Vault.hpp"
#include <algorithm>
#include "../external/ChronoBenchmark.hpp"

/**
   lambda function for size comparison:
   [](const Account& acc1, const Account& acc2){ return acc1.username < acc2.username };
 */

int main()
{
   MasterCredential loggedUser{"initialUser", "initialPass"};


   VaultItem item0("johndoe0", "doughy1231", "amazon", "this account has prime", "no tag under this one");
   VaultItem item1("johndoe001", "doughy1232", "amazon", "this account has prime", "");
   VaultItem item2("johndoe49", "doughy1233", "discord", "this account has prime", "-p");
   VaultItem item3("johndoe23", "doughy1234", "discord", "this account has prime", "-w");
   VaultItem item4("johndoe4", "doughy1235", "amazon", "this account has prime", "-s");
   VaultItem item5("johndoe4", "doughy1235", "amazon", "this account has prime", "-s");
   VaultItem item6("twitter9", "twiter1234", "twitter", "shitposting", "-q");
   VaultItem item7("johndoe4", "doughy1235", "amazon", "test", "-w");
   VaultItem item8("twitter3", "tweeter4321", "twitter", "public account", "-p");
   VaultItem item9("Reallydumbemail@gmail.com", "Mygmailaccount123", "google", "my google account", "-s");

   Vault vault{ };

   vault.vaultContainer[item0.property.domain].push_back(item0);
   vault.vaultContainer[item1.property.domain].push_back(item1);
   vault.vaultContainer[item2.property.domain].push_back(item2);
   vault.vaultContainer[item3.property.domain].push_back(item3);
   vault.vaultContainer[item4.property.domain].push_back(item4);
   vault.vaultContainer[item5.property.domain].push_back(item5);
   vault.vaultContainer[item6.property.domain].push_back(item6);
   vault.vaultContainer[item7.property.domain].push_back(item7);
   vault.vaultContainer[item8.property.domain].push_back(item8);
   vault.vaultContainer[item9.property.domain].push_back(item9);


   Timer timer{ };

   // use const for printing
   // non const for when sorting buckets on map<>
   for ( auto& entry : vault.vaultContainer)
   {
      std::cout << "========" << entry.first << "========\n";


      // sort vector
      std::sort(entry.second.begin(), entry.second.end());

      for (auto it = entry.second.begin(); it != entry.second.end(); ++it)
      {
         // honestly assign *it to its type so that it reduces  the amount of dereference calls.
         // should aim to reduce as many new gets as possible, include std::string::size() calls, just assign it to a variable for reference.
         std::cout << (*it).username << " " << (*it).password << " " << (*it).property.domain << " " << (*it).property.description << " " << (*it).property.tag << "\n";
      }
   }

   // std::cout << "\n\nBUCKETS: " << vault.vault.size();

   // delete timer;

   return 0;
}
