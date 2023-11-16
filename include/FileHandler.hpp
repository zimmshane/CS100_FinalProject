#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <iostream>
#include <fstream>
#include "Account.hpp"

class FileHandler
{
public:
   static bool IsUserVaultExist(const std::string& username);
   static void CreateVaultFile(const MasterCredential& master);
   static bool IsVaultPasswordMatch(const MasterCredential& master);
};

#endif // !FILEHANDLER_HPP