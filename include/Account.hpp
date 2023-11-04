#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account // maybe make it a struct instead
{
public:
   Account(const std::string& user, const std::string& pass)
      : username(user), password(pass) { }
   virtual std::string GetUsername() const = 0;
   virtual std::string GetPassword() const = 0;

protected:
   std::string username;
   std::string password;
};

class MasterCredentials : public Account
{
public:
   MasterCredentials(const std::string& user, const std::string& pass)
      : Account(user, pass), hashedUserName(""), hashedPassWord("") { }
   std::string GetUsername() const { return username; }
   std::string GetPassword() const { return password; }

private:
   std::string hashedUserName;
   std::string hashedPassWord;
};

class VaultItem : public Account
{
public:

private:

};



#endif // !ACCOUNT_HPP