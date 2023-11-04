#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account
{
public:
   Account(const std::string& u, const std::string& p)
      : username(u), password(p) { }
   std::string GetUsername() const { return username; }
   std::string GetPassword() const { return password; }

protected:
   std::string username;
   std::string password;
};

class MasterCredentials : public Account
{
public:
   MasterCredentials(const std::string& user, const std::string& pass)
      : Account(user, pass) { }

private:
   std::string hashedUserName;
   std::string hashedPassWord;
   std::string userDefinedKey;
};

class VaultItem : public Account
{
public:
   VaultItem(const std::string& user, const std::string& pass, const std::string& d, const std::string& desc, const std::string& t)
      : Account(user, pass), domain(d), description(desc), tag(t) { }

private:
   std::string domain;
   std::string description;
   std::string tag;
};

#endif // !ACCOUNT_HPP