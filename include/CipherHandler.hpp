#ifndef CIPHERHANDLER_HPP
#define CIPHERHANDLER_HPP

#include "../external/cryptopp/scrypt.h"
#include "../external/cryptopp/hex.h"
#include "PasswordManager.hpp"

class CipherHandler
{
public:
   std::string ScryptKDF(const std::string& inputStr);

};

#endif // !CIPHERHANDLER_HPP
