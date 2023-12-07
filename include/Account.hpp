#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

// can afford to use public interfaces, no more changes to hierarchy
class Account
{
public:
   Account() { }
   Account(const std::string& u, const std::string& p) : username(u), password(p) { }
   ~Account() { }

   std::string username;
   std::string password;
};

class MasterCredential : public Account
{
public:
   MasterCredential() { }
   MasterCredential(const std::string& u, const std::string& p) : Account(u, p) { }
   ~MasterCredential() { }

   struct HashedCredential
   {
      std::string hashedUsername;
      std::string hashedPassword;
      std::string key;
   };

   HashedCredential hashed;
};

class VaultItem : public Account
{
public:
   VaultItem() { }
   VaultItem(const std::string& u, const std::string& p, const std::string& d, const std::string& desc, const std::string& t)
      : Account(u, p), property{d, desc, t} { }
   ~VaultItem() { }

   // comparative overloading for Account object username comparison for std::sort
   bool operator<(const Account& right) const
   {
      return (username < right.username);
   }

   struct ItemProperty
   {
      std::string domain;
      std::string description;
      std::string tag;
   };

   ItemProperty property;
};

#endif // !ACCOUNT_HPP