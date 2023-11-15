#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <fstream>
#include <iostream>

class FileHandler
{
public:
   static bool DoesUserVaultExist(const std::string& user);
   static void CreateVaultFile(const std::string& vaultName, const std::string& password);
};

#endif // !FILEHANDLER_HPP