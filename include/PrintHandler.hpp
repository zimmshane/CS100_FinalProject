#ifndef PRINTHANDLER_HPP
#define PRINTHANDLER_HPP

#include <iostream>
#include <vector>
#include "Account.hpp"

class Vault;

class PrintHandler {
public:
   static void PrintVault(const Vault* vault);
   static void printVector(const std::vector<VaultItem>& list);
   static void printVaultItem(const VaultItem& vitem);
   static void PrintMainMenu();
};

#endif // !PRINTHANDLER_HPP