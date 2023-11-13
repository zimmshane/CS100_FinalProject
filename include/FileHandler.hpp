#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <fstream>
#include <iostream>

class FileHandler
{
public:
   static bool DoesUserVaultExist(const std::string& user);
};

#endif // !FILEHANDLER_HPP