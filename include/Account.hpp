#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <iostream>

// can afford to use public interfaces, no more changes to hierarchy
struct Account
{
   Account(const std::string& u, const std::string& p) : username(u), password(p) { }

   std::string username;
   std::string password;
};

struct MasterCredential : Account
{
   MasterCredential(const std::string& u, const std::string& p)
      : Account(u, p) { }

   struct HashedCredential
   {
      std::string hashedUserName;
      std::string hashedPassWord;
      std::string key;
   };

   HashedCredential hashed;
};

struct VaultItem : Account
{
   VaultItem(const std::string& u, const std::string& p, const std::string& d, const std::string& desc, const std::string& t)
      : Account(u, p), property{d, desc, t} { }

   struct ItemProperty
   {
      std::string domain;
      std::string description;
      std::string tag;
   };
   ~VaultItem(){}

   ItemProperty property;
};

#endif // !ACCOUNT_HPP