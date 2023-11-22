#ifndef PASSWORDQUALITYHANDLER_HPP
#define PASSWORDQUALITYHANDLER_HPP

#include "Account.hpp"
#include "Vault.hpp"

class PasswordQualityHandler
{
public:
    static bool IsPasswordStrong(const std::string& pass);
    static bool IsPasswordRepeating(const std::string& pass);
};

#endif // !PASSWORDQUALITYHANDLER_HPP
