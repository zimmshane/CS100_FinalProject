#ifndef PRINTHANDLER_HPP
#define PRINTHANDLER_HPP

#include <iostream>
#include "Vault.hpp"

class PrintHandler
{
public:
   static void PrintVault(const Vault& vault);
   void PrintMenu();
};

#endif // !PRINTHANDLER_HPP