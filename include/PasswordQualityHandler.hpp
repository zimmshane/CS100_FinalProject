#ifndef PASSWORDQUALITYHANDLER_HPP
#define PASSWORDQUALITYHANDLER_HPP

#include <iostream>
#include "Account.hpp"
#include "Vault.hpp"
#include "SearchHandler.hpp"

class PasswordQualityHandler
{
public:
    static bool IsPasswordStrong(const std::string& pass);
    static bool IsPasswordRepeating(const std::string pass, const Vault& vault);
};

#endif // !PASSWORDQUALITYHANDLER_HPP
