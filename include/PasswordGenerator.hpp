#ifndef PASSWORDGENERATOR_HPP
#define PASSWORDGENERATOR_HPP

#include <iostream>
#include "Account.hpp"
#include "Vault.hpp"

class PasswordGenerator
{
public:
    static string GeneratePassword();
};

#endif // !PASSWORDGENERATOR_HPP