#ifndef SEARCHHANDLER_HPP
#define SEARCHHANDLER_HPP

#include <iostream>
#include "Account.hpp"

class SearchHandler
{
public:
    static void Search(const std::string& domain, const std::string& username); // domain specific username search
    static void Search(const std::string& username); // wild card thorough vault search
    static bool SearchDuplicatePassword(const std::string& password); // take a password and run through every key domain
    static VaultItem& ReturnReference(const std::string& username); // returns item reference for modification
};

#endif // !SEARCHHANDLER_HPP