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

   if (domainsContainingUsername.empty())
   {
      return;
   }

   // refactor into PrintHandler for parameter:
   // std::vector<std::vector<VaultItem>::const_iterator>
   for (size_t i { 0 }; i < domainsContainingUsername.size(); ++i)
   {
      std::cout << i << " " << (*domainsContainingUsername.at(i)).property.domain << " | "
                           << (*domainsContainingUsername.at(i)).username << " | "
                           << (*domainsContainingUsername.at(i)).property.description<< "\n";
   }

   size_t indexInput;
   UserInputHandler::GetIndex(indexInput, domainsContainingUsername.size());

   // sentinel value to exit vault manip
   if (indexInput == size_t(-1))
   {
      return;
   }

   // vault at the hash key value of the domain given by the iterator, erase at the vector of the hash key
   vaultContainer.at((*domainsContainingUsername.at(indexInput)).property.domain).erase(domainsContainingUsername.at(indexInput));

   // check key container (vector) if it is empty after an element is removed from it
   if (vaultContainer.at((*domainsContainingUsername.at(indexInput)).property.domain).empty())
   {
      // remove the key with an empty vector
      vaultContainer.erase((*domainsContainingUsername.at(indexInput)).property.domain);
      std::cout << "empty domain key removed\n";
   }

   // if (indexInput < domainsContainingUsername.size() && !(domainsContainingUsername.empty()))
   // {
   //    // vault at the hash key value of the domain given by the iterator, erase at the vector of the hash key
   //    vaultContainer.at((*domainsContainingUsername.at(indexInput)).property.domain).erase(domainsContainingUsername.at(indexInput));

   //    // check key container (vector) if it is empty after an element is removed from it
   //    if (vaultContainer.at((*domainsContainingUsername.at(indexInput)).property.domain).empty())
   //    {
   //       // remove the key with an empty vector
   //       vaultContainer.erase((*domainsContainingUsername.at(indexInput)).property.domain);
   //       std::cout << "empty domain key removed\n";
   //    }
   // }
}

void Vault::ModifyItem(const std::string& usernameForModification)
{
   std::vector<std::vector<VaultItem>::iterator> domainVectorPositions;

   for (auto& keyDomainIter : vaultContainer)
   {
      auto iter = std::find_if(keyDomainIter.second.begin(), keyDomainIter.second.end(), [usernameForModification](const VaultItem& item) { return (item.username == usernameForModification); });

      if (iter != keyDomainIter.second.end())
      {
         domainVectorPositions.push_back(iter);
      }
   }

   // check for empty then return early
   if (domainVectorPositions.empty())
   {
      return;
   }

   // if reach here, that means not empty
   for (size_t i { 0 }; i < domainVectorPositions.size(); ++i)
   {
      std::cout << i << " " << (*domainVectorPositions.at(i)).property.domain << " | "
                           << (*domainVectorPositions.at(i)).username << " | "
                           << (*domainVectorPositions.at(i)).property.description<< "\n";
   }

   size_t indexInput;
   UserInputHandler::GetIndex(indexInput, domainVectorPositions.size());

   // sentinel value to exit vault manip
   if (indexInput == size_t(-1))
   {
      return;
   }

   // vault at the hash key value of the domain given by the iterator, erase at the vector of the hash key
   UserInputHandler::GetGenericInput("><>username: ", (*domainVectorPositions.at(indexInput)).username);
   UserInputHandler::GetItemPassword((*domainVectorPositions.at(indexInput)).password);
   UserInputHandler::GetGenericInput("><>description: ", (*domainVectorPositions.at(indexInput)).property.description);
   UserInputHandler::GetGenericInput("><>tag: ", (*domainVectorPositions.at(indexInput)).property.tag);

   // if (!(domainVectorPositions.empty()) && (indexInput < domainVectorPositions.size()) && (indexInput > -1))
   // {
   //    // vault at the hash key value of the domain given by the iterator, erase at the vector of the hash key
   //    UserInputHandler::GetGenericInput("><>username: ", (*domainVectorPositions.at(indexInput)).username);
   //    UserInputHandler::GetItemPassword((*domainVectorPositions.at(indexInput)).password);
   //    UserInputHandler::GetGenericInput("><>description: ", (*domainVectorPositions.at(indexInput)).property.description);
   //    UserInputHandler::GetGenericInput("><>tag: ", (*domainVectorPositions.at(indexInput)).property.tag);
   // }

   return;
}
