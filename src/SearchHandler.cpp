#include "../include/SearchHandler.hpp"

std::vector<VaultItem> SearchHandler::returnAll(const std::string &search, const Vault &vlt){
    std::vector<VaultItem> results;
    for (auto& entry : vlt.vault){
        if (entry.first == search){ // if domain matches search, add all accounts to result
            for (auto it = entry.second.begin(); it != entry.second.end(); ++it){
                results.push_back((*it));
            } 
        } 
        else{                       //search usernames in domain
        for (auto it = entry.second.begin(); it != entry.second.end(); ++it){ 
            if (it->username == search){
                results.push_back(*it);
                }
            }
        }
    }
    return results;
}

void SearchHandler::Search(const std:: string&)
// void SearchHandler::Search(const std::string& username)
// {

//     return;
// }

// avoid this by making vault values a map as well for keys of username to avoid all collisions               vvv username string
// linear search bad, replace data structure later for std::unordered_map<std::string, std::unordered_map<std::string, VaultItem>>
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
