#ifndef VAULT_HPP
#define VAULT_HPP

#include "Account.hpp"
#include <algorithm>
// #include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include "Account.hpp"
#include "SearchHandler.hpp"
#include "UserInputHandler.hpp"

class Vault
{
public:
   Vault() { }
   ~Vault() { }
   bool AddItem(const VaultItem& item);
   void DeleteItem(const std::string& username);
   void ModifyItem(const std::string& username);

   // put this inside PasswordManager class later
   // std::unordered_map<std::string, std::vector<VaultItem>> GetVault() { return vault; }

   std::unordered_map<std::string, std::vector<VaultItem>> vaultContainer;

   // std::unordered_map<std::string, std::unordered_map<std::string, VaultItem>> keyDomainKeyUsername;
};

#endif // !VAULT_HPP