#include "../include/Vault.hpp"

bool Vault::AddAccount(const VaultItem& item)
{
   vault[item.property.domain].push_back(item);

   return true;
}