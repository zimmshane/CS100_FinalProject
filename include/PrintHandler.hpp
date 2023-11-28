#ifndef PRINTHANDLER_HPP
#define PRINTHANDLER_HPP

#include <iostream>
#include "Vault.hpp"

class PrintHandler
{
public:
   static void PrintMainMenu();
   static void PrintItem(const VaultItem& item);
   static void PrintVault(const Vault& vault);
};

#endif // !PRINTHANDLER_HPP