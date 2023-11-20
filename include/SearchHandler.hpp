#ifndef SEARCHHANDLER_HPP
#define SEARCHHANDLER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Account.hpp"
#include "Vault.hpp"

class Vault;
class VaultItem;

class SearchHandler{
public:
static std::vector<VaultItem> returnAll(const std::string &search, const Vault& vlt); // return a vector with all search results
static void Search(const std::string& domain, const std::string& username); // domain specific username search
static void Search(const std::string& username); // wild card thorough vault search
static bool SearchDuplicatePassword(const std::string& password); // take a password and run through every key domain
static VaultItem& ReturnReference(const std::string& username); // returns item reference for modification

};



#endif
