#include "../include/FileHandler.hpp"

bool FileHandler::DoesUserVaultExist(const std::string& user)
{
   std::string fileName{user + ".vault"};

   std::cout << fileName << "\n";
}