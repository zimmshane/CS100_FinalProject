#include "../include/FileHandler.hpp"

bool FileHandler::IsUserVaultExist(const std::string& username)
{
   std::string fileName{username + ".vault"};

   std::ifstream iFS{fileName};

   if (iFS.good())
   {
      std::cout << "\tfound: " << fileName << "\n";
      return true;
   }

   std::cout << "\tnot found: " << fileName << "\n";

   return false;
}

void FileHandler::CreateVaultFile(const MasterCredential& master)
{
   std::ofstream oFS{master.username + ".vault"}; // generates .vault file via ofstream
   if (oFS.is_open())
   {
      oFS << master.password << "\n"; // first line is vault password
      oFS << "username,password,domain,description,tag";

      std::cout << "\tvault sucessfully registered\n";
   }

   return;
}

bool FileHandler::IsVaultPasswordMatch(const MasterCredential& master)
{
   std::ifstream iFS{master.username + ".vault"};
   std::string buffer;

   if (iFS.is_open())
   {
      std::getline(iFS, buffer);

      if (buffer == master.password)
      {
         std::cout << "\tgood vault password match\n";

         return true;
      }
   }

   std::cout << "\tbad vault password match\n";

   return false;
}

void FileHandler::LoadVaultFile(const std::string vaultName, Vault& vault)
{
   // logging in already checks file IsUserVaultExist, assume ifstream opens
   std::ifstream iFS(vaultName + ".vault");

   std::string rawString;
   std::string username;
   std::string password;
   std::string domain;
   std::string description;
   std::string tag;

   std::string dummy;

   // skip first two lines to avoid master password and column parameter
   for (int i = 0; i < 2; ++i)
   {
      std::getline(iFS, rawString);
   }

   while (std::getline(iFS, rawString))
   {
      // load the buffer in new iss
      std::istringstream iSS(rawString);

      // we know there are 5 parameters because we made it up
      // extract per delimiter "comma separated values"
      std::getline(iSS, username, ',');
      std::getline(iSS, password, ',');
      std::getline(iSS, domain, ',');
      std::getline(iSS, description, ',');
      std::getline(iSS, tag, ',');

      vault.vault[domain].push_back(VaultItem(username, password, domain, description, tag));
   }

   return;
}