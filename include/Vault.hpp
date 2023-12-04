#ifndef VAULT_HPP
#define VAULT_HPP

#include <algorithm>
// #include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include "Account.hpp"

// bad includes, causes circular dependency
//#include "PrintHandler.hpp"
// #include "SearchHandler.hpp"

class Vault
{
public:
   Vault() { }
   ~Vault() { }
   bool AddItem(const VaultItem& item);
   void DeleteItem(const std::string& usernameForDeletion);
   // doesn't make sense to change domain of an account to another domain
   void ModifyItem(const std::string& usernameForModification);

   // put this inside PasswordManager class later
   // std::unordered_map<std::string, std::vector<VaultItem>> GetVault() { return vault; }

   std::unordered_map<std::string, std::vector<VaultItem>> vaultContainer;

   // std::unordered_map<std::string, std::unordered_map<std::string, VaultItem>> keyDomainKeyUsername;
};

#endif // !VAULT_HPP