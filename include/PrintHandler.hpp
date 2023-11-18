#ifndef PRINTHANDLER_HPP
#define PRINTHANDLER_HPP

#include <iostream>
#include "Vault.hpp"

class PrintHandler
{
public:
   static void PrintVault(const Vault& vault);
   static void printVector(const std::vector<VaultItem> list);
};

#endif // !PRINTHANDLER_HPP