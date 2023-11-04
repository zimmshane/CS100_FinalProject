#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

struct Account
{
   Account(const std::string& u, const std::string& p)
      : username(u), password(p) { }

   std::string username;
   std::string password;
};

struct MasterCredentials : Account
{
   MasterCredentials(const std::string& u, const std::string& p)
      : Account(u, p) { }

   std::string hashedUserName;
   std::string hashedPassWord;
};

struct VaultItem : Account
{
   VaultItem(const std::string& u, const std::string& p, const std::string& d, const std::string& desc, const std::string& t)
      : Account(u, p), domain(d), description(desc), tag(t) { }

   std::string domain;
   std::string description;
   std::string tag;
};

#endif // !ACCOUNT_HPP