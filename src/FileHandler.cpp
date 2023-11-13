#include "../include/FileHandler.hpp"

bool FileHandler::DoesUserVaultExist(const std::string& user)
{
   std::string fileName{user + ".vault"};

   std::fstream fs{fileName};

   if (fs.good())
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