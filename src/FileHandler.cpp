#include "../include/FileHandler.hpp"

bool FileHandler::IsUserVaultExist(const std::string& username)
{
   std::string fileName{username + ".vault"};

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
      oFS << password << "\n"; // first line is vault password
      oFS << "username,password,domain,description,tag";
      std::cout << "><>vault sucessfully registered\n";
   }

   return;
}

bool IsVaultPasswordMatch(const std::string& username, const std::string& userPassword)
{
   std::ifstream iFS{username + ".vault"};
   std::string buffer;

   if (iFS.is_open())
   {
      std::getline(iFS, buffer);

      if (buffer == userPassword)
      {
         std::cout << "good vault password match\n";
         return true;
      }
   }

   std::cout << "bad vault password match\n";

   return false;
}