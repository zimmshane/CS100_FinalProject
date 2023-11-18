#ifndef VAULT_HPP
#define VAULT_HPP

#include "Account.hpp"
// #include <map>
#include <unordered_map>
#include <vector>

class Vault
{
public:
   Vault() { }
   ~Vault() { }

   std::unordered_map<std::string, std::vector<VaultItem>> vault;
};

#endif // !VAULT_HPP