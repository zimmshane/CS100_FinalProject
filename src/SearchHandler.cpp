#include "../include/SearchHandler.hpp"
#include"../include/Account.hpp"
// void SearchHandler::Search(const std::string& username)
// {

//     return;
// }

// avoid this by making vault values a map as well for keys of username to avoid all collisions               vvv username string
// linear search bad, replace data structure later for std::unordered_map<std::string, std::unordered_map<std::string, VaultItem>>
bool SearchHandler::IsUsernameExistInDomainVector(const std::string username, const std::vector<VaultItem>& itemVector)
{
   for (const auto& iter : itemVector)
      if (iter.username == username)
         return true;

   return false;
}

bool SearchHandler::SearchDuplicatePassword(const std::string pass, const Vault& vault){
   for (auto& entry : vault.vault)
   {
      for (auto it = entry.second.begin(); it != entry.second.end(); ++it)
      {
         if((*it).password == pass){
            std::cout << (*it).username << " in " << (*it).property.domain << "\n";
            return true;
         }
      }
   }
   return false;
}