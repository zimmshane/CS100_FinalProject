#ifndef SEARCHHANDLER_HPP
#define SEARCHHANDLER_HPP

#include "Vault.hpp"
// #include <algorithm>

class SearchHandler
{
public:
    static void Search(const std::string& domainForSearch, const std::string& username, const Vault& vault ); // domain specific username search
    static bool IsUsernameExistInDomainVector(const std::string username, const std::vector<VaultItem>& itemVector); // does username exist in domain key's vector?
    static bool SearchDuplicate(const std::string domain, const Vault& vault); // run through every key domain for duplicate users
};

#endif // !SEARCHHANDLER_HPP