#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

// can afford to use public interfaces, no more changes to hierarchy
struct Account
{
   std::string username;
   std::string password;
};

struct MasterCredentials : Account
{
   MasterCredentials(const std::string& u, const std::string& p)
      : Account{u, p} { }

   struct HashedCredentials
   {
      std::string hashedUserName;
      std::string hashedPassWord;
      std::string key;
   };

   HashedCredentials hashed;
};

struct VaultItem : Account
{
   VaultItem(const std::string& u, const std::string& p, const std::string& d, const std::string& desc, const std::string& t)
      : Account{u, p}, properties{d, desc, t} { }

   struct ItemProperties
   {
      std::string domain;
      std::string description;
      std::string tag;
   };

   ItemProperties properties;
};

#endif // !ACCOUNT_HPP