#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "UserInputHandler.hpp"
#include "FileHandler.hpp"
#include "CipherHandler.hpp"

class LoginHandler
{
public:
   static bool IsLoginInfoMatchingVault(MasterCredential& master);
   static void RegisterVault(const MasterCredential& master);
};

#endif // !LOGIN_HPP
