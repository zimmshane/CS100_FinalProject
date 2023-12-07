#ifndef CIPHERHANDLER_HPP
#define CIPHERHANDLER_HPP

#include "../external/cryptopp/scrypt.h"
#include "../external/cryptopp/hex.h"
#include "PasswordManager.hpp"

class CipherHandler
{
public:
   static std::string ScryptHashKDF(const std::string& inputStr);

};

#endif // !CIPHERHANDLER_HPP
