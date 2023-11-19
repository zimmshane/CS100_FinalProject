#ifndef SEARCHHANDLER_HPP
#define SEARCHHANDLER_HPP

#include <iostream>
#include <vector>
#include <string>

class Vault;
class Account;
class PasswordManager;
class VaultItem;

class SearchHandler{
public:
static std::vector<VaultItem> returnAll(const std::string &search, const Vault& vlt);

};



#endif