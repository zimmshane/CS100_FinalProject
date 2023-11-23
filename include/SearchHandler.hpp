#ifndef SEARCHHANDLER_HPP
#define SEARCHHANDLER_HPP

#include "Account.hpp"
#include "Vault.hpp"
// #include <algorithm>

class SearchHandler
{
public:
    // static void Search(const std::string& domain, const std::string& username); // domain specific username search
    // static void Search(const std::string& username); // wild card thorough vault search
    static bool IsUsernameExistInDomainVector(const std::string username, const std::vector<VaultItem>& itemVector); // does username exist in domain key's vector?
    static bool SearchDuplicate(const std::string domain, const Vault& vault); // run through every key domain for duplicate users
    static VaultItem& ReturnReference(const std::string& username); // returns item reference for modification
};

#endif // !SEARCHHANDLER_HPP