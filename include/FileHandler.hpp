#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <fstream>
#include <iostream>

class FileHandler
{
public:
   static bool IsUserVaultExist(const std::string& username);
   static void CreateVaultFile(const std::string& vaultName, const std::string& password);
   static bool IsVaultPasswordMatch(const MasterCredential master);
};

#endif // !FILEHANDLER_HPP