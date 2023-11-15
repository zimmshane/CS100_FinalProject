#include "../include/FileHandler.hpp"

bool FileHandler::DoesUserVaultExist(const std::string& user)
{
   std::string fileName{user + ".vault"};

   std::ifstream iFS{fileName};

   if (iFS.good())
   {
      std::cout << "><>found: " << fileName << "\n";
      return true;
   }
   else
   {
      std::cout << "><>not found: " << fileName << "\n";
      return false;
   }

   return false;
}

void FileHandler::CreateVaultFile(const std::string& vaultName, const std::string& password)
{
   std::ofstream oFS{vaultName}; // generates .vault file via ofstream

   if (oFS.is_open())
   {
      oFS << password; // first line is vault password
      std::cout << "><>vault sucessfully registered\n";
      return;
   }

   std::cout << "><>bad file, try a different username\n";

   return;
}