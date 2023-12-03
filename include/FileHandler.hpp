#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <iostream>
#include <fstream>
#include <sstream> // parse ',' delimiter overload
#include "Vault.hpp"
#include "PasswordManager.hpp"

struct Config;

class FileHandler
{
public:
   static bool IsUserVaultExist(const std::string& username);
   static bool IsVaultPasswordMatch(const MasterCredential& master);
   static void CreateVaultFile(const MasterCredential& master);
   static void LoadVaultFile(const std::string& vaultName, Vault& vault);
   static void ParseConfig(Config& config, const std::string fileName);
   static void WriteVaultToFile(const MasterCredential& currentUser, const std::unordered_map<std::string, std::vector<VaultItem>>& container);
};

#endif // !FILEHANDLER_HPP