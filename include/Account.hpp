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
   MasterCredentials(const std::string& user, const std::string& pass)
      : Account(user, pass) { }
   std::string hashedUserName;
   std::string hashedPassWord;
   std::string userDefinedKey;

};

struct VaultItem : Account
{
   VaultItem(const std::string& user, const std::string& pass, const std::string& d, const std::string& desc, const std::string& t)
      : Account(user, pass), domain(d), description(desc), tag(t) { }
   std::string domain;
   std::string description;
   std::string tag;
};

#endif // !ACCOUNT_HPP