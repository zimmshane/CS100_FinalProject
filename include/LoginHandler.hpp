#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "UserInputHandler.hpp"
#include "FileHandler.hpp"

class LoginHandler
{
public:
   static bool GetLoginInfo(MasterCredential& info);
   static void RegisterVault(const MasterCredential& master);
};

#endif // !LOGIN_HPP
