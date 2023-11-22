#include "../include/Vault.hpp"

bool Vault::AddItem(const VaultItem& item)
{
   if (!(SearchHandler::IsUsernameExistInDomainVector(item.username, vault[item.property.domain]))) // pass in vault at specified domain key value to get vector
   {
      vault[item.property.domain].push_back(item);
      return true;
   }

   std::cout << "account already exists in domain\n";

   return false;
}