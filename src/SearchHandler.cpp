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
{

    return;
}
