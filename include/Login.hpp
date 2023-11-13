#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "../include/Account.hpp"
#include <iostream>

class Login
{
public:
   static void GetLoginInfo(MasterCredential& info);
   static void RegisterVault(const std::string& username, std::string& newPass);
};

#endif // !LOGIN_HPP
