#ifndef PRINTHANDLER_HPP
#define PRINTHANDLER_HPP

#include <iostream>
#include "Vault.hpp"

class PrintHandler
{
public:
   static void PrintVault(const Vault& vault);
   static void PrintMainMenu();
};

#endif // !PRINTHANDLER_HPP