#ifndef VAULT_HPP
#define VAULT_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include "Account.hpp"

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