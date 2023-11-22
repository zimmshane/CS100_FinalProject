#include "../include/Vault.hpp"

bool Vault::AddItem(const VaultItem& item)
{
   if (!(SearchHandler::IsUsernameExistInDomainVector(item.username, vaultContainer[item.property.domain]))) // pass in vault at specified domain key value to get vector
   {
      vaultContainer[item.property.domain].push_back(item);
      return true;
   }

   std::cout << "account already exists in domain\n";

   return false;
}

void Vault::DeleteItem(const std::string& usernameForDeletion)
{
   std::vector<std::vector<VaultItem>::const_iterator> domainsContainingUsername;

   //  get vector of domains that contain an item with username
   // we are sure of non duplicate during std::any_of due to AddItem() declining duplicate usernames per domain
   for (const auto& keyDomainIter : vaultContainer)
   {
      // lambda function [capture variables for use](parameter of function sent in by iterator) { FUNCTION_HERE }
      auto iter = std::find_if(keyDomainIter.second.begin(), keyDomainIter.second.end(), [usernameForDeletion](const VaultItem& item) { return (item.username == usernameForDeletion); });

      // make sure not end to prevent adding iterators that may have bad access
      if (iter != keyDomainIter.second.end())
      {
         domainsContainingUsername.push_back(iter);
      }
   }

   for (size_t i { 0 }; i < domainsContainingUsername.size(); ++i)
   {
      std::cout << i << " " << (*domainsContainingUsername.at(i)).property.domain << " | "
                           << (*domainsContainingUsername.at(i)).username << " | "
                           << (*domainsContainingUsername.at(i)).property.description<< "\n";
   }

   size_t indexInput;
   std::cout << "><>index to delete: ";
   UserInputHandler::GetIndex(indexInput);

   if (indexInput < domainsContainingUsername.size() && !(domainsContainingUsername.empty()))
   {
      // vault at the hash key value of the domain given by the iterator, erase at the vector of the hash key
      vaultContainer.at((*domainsContainingUsername.at(indexInput)).property.domain).erase(domainsContainingUsername.at(indexInput));

      // check key container (vector) if it is empty after an element is removed from it
      if (vaultContainer.at((*domainsContainingUsername.at(indexInput)).property.domain).empty())
      {
         // remove the key with an empty vector
         vaultContainer.erase((*domainsContainingUsername.at(indexInput)).property.domain);
         std::cout << "empty domain key removed\n";
      }
   }
}