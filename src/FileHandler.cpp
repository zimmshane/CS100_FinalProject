#include "../include/FileHandler.hpp"

bool FileHandler::IsUserVaultExist(const std::string& username)
{
   std::string fileName{username + ".vault"};

   std::ifstream iFS{fileName};

   if (iFS.good())
   {
      std::cout << "found: " << fileName << "\n";
      return true;
   }
   else
   {
      std::cout << "not found: " << fileName << "\n";
      return false;
   }

   return false;
}

void FileHandler::CreateVaultFile(const MasterCredential& master)
{
   std::ofstream oFS{master.username + ".vault"}; // generates .vault file via ofstream

   if (oFS.is_open())
   {
      oFS << master.password << "\n"; // first line is vault password
      oFS << "username,password,domain,description,tag";
      std::cout << "vault sucessfully registered\n";
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
         std::cout << "good vault password match\n";
         return true;
      }
   }

   std::cout << "bad vault password match\n";

   return false;
}