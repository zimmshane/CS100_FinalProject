#ifndef SEARCHHANDLER_HPP
#define SEARCHHANDLER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Vault.hpp"
#include "Account.hpp"


class SearchHandler{

public:
static std::vector<VaultItem> returnAll(const std::string &search);


};



#endif