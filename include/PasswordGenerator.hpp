#ifndef PASSWORDGENERATOR_HPP
#define PASSWORDGENERATOR_HPP

#include <iostream>
#include "Account.hpp"
#include "Vault.hpp"
#include <stdlib.h>
#include <algorithm>
#include <fstream>

class PasswordGenerator
{
public:
    static std::string GeneratePassword();
};

#endif // !PASSWORDGENERATOR_HPP