#ifndef VAULT_HPP
#define VAULT_HPP

#include "Account.hpp"
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class Vault
{
public:
   Vault() { }
   ~Vault() { }

   // put this inside PasswordManager class later
   // std::unordered_map<std::string, std::vector<VaultItem>> GetVault() { return vault; }

   std::unordered_map<std::string, std::vector<VaultItem>> vault;
};

#endif // !VAULT_HPP