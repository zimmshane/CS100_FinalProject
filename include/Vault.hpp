#ifndef VAULT_HPP
#define VAULT_HPP


#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

class Account;
class SearchHandler;
class VaultItem;
class PasswordManager;
class MasterCredential;


class Vault
{
public:
  std::unordered_map<std::string, std::vector<VaultItem>> vault;

   Vault() { }
   ~Vault() { }
   bool addAccount(const VaultItem&);
   void deleteAccount(const std::string&);
   void forceDeleteAccount(const VaultItem&);
   void modifyAccount(const std::string&);
   VaultItem findFromSearch(const std::string&);
   std::vector<VaultItem>::iterator getPositionedItr(const VaultItem& target); //returns a vector iterator at the location of a specific vault item
   
   // put this inside PasswordManager class later
   // std::unordered_map<std::string, std::vector<VaultItem>> GetVault() { return vault; }

 
};

#endif // !VAULT_HPP