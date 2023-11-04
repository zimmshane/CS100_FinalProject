#ifndef VAULT_HPP
#define VAULT_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include "Account.hpp"

class Vault
{
private:
   std::unordered_map<std::string, std::vector<VaultItem>> vault;
};

#endif // !VAULT_HPP