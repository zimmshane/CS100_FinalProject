#ifndef SEARCHHANDLER_HPP
#define SEARCHHANDLER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Vault.hpp"
#include "Account.hpp"


class SearchHandler{

public:
std::vector<VaultItem> returnAll(std::string &search);


};



#endif