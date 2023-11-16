#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "../include/Account.hpp"
#include <iostream>
#include "UserInputHandler.hpp"

class LoginHandler
{
public:
   static bool GetLoginInfo(MasterCredential& info);
   static void RegisterVault(const MasterCredential& master);
};

#endif // !LOGIN_HPP
