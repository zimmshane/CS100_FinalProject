#ifndef VAULT_HPP
#define VAULT_HPP

#include "Account.hpp"
// #include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include "Account.hpp"
#include "PrintHandler.hpp"
#include "SearchHandler.hpp"

class Vault
{
public:
   Vault() { }
   ~Vault() { }
   bool addAccount(const VaultItem&);
   void deleteAccount(const std::string&);
   void modifyAccount(const std::string&);
   
   // put this inside PasswordManager class later
   // std::unordered_map<std::string, std::vector<VaultItem>> GetVault() { return vault; }

   std::unordered_map<std::string, std::vector<VaultItem>> vault;
};

#endif // !VAULT_HPP