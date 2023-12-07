#include "../include/SearchHandler.hpp"

void SearchHandler::Search(const std::string& domainForSearch, const std::string& username, const Vault& vault){
   try{
      std::vector<VaultItem> itemsAtDomain = vault.vaultContainer.at(domainForSearch);
   }
   catch(const std::exception& e){
      std::cout<<"No account with specified domain\n";
      if(vault.vaultContainer.empty() == true){
         return;
      }
      std::cout<<"Other domains:\n";
      int counter = 1;
      for (auto& entry : vault.vaultContainer)
      {
         for (auto it = entry.second.begin(); it != entry.second.end(); ++it)
         {
            std::cout << counter<< ". " << (*it).property.domain << "\n";
            counter++;
         }
      }
      return;
   }


   std::vector<VaultItem> itemsAtDomain = vault.vaultContainer.at(domainForSearch);
   for (const auto& iter : itemsAtDomain)
   {
      if (iter.username == username)
      {
         std::cout << "domain: " << (iter).property.domain << "\n"
            << "username: " << (iter).username << "\n"
            << "password: " << (iter).password << "\n"
            << "description: " << (iter).property.description << "\n"
            << "tag: " << (iter).property.tag << "\n";
         return;
      }
   }
}

bool SearchHandler::IsUsernameExistInDomainVector(const std::string username, const std::vector<VaultItem>& itemVector)
{
   for (const auto& iter : itemVector)
   {
      if (iter.username == username)
      {
         return true;
      }

   }

   return false;
}

bool SearchHandler::SearchDuplicate(const std::string domain, const Vault& vault){
   bool isRepeating = false;
   for (auto& entry : vault.vaultContainer)
   {
      for (auto it = entry.second.begin(); it != entry.second.end(); ++it) {
         if((*it).property.domain == domain){
            isRepeating = true;
            std::cout << (*it).username << " has a duplicate domain of " << (*it).property.domain << "\n";
         }
      }
   }
   if(isRepeating){
      return true;
   }
   return false;
}