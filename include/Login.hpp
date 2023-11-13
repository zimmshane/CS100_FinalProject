#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "../include/Account.hpp"
#include <iostream>

class Login
{
public:
   static void GetLoginInfo(MasterCredential& info);
};

#endif // !LOGIN_HPP
