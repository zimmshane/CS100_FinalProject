#include "../include/vault.hpp"

bool Vault::addAccount(const VaultItem &vlt)
{
    if (SearchHandler::SearchDuplicate(vlt.property.domain))
    { // I'm sure this wont be sufficent to find duplicates
        for (auto it = this->vault[vlt.property.domain].begin(); it != this->vault[vlt.property.domain].end(); ++it)
        {
            if (it->username == vlt.username)
            {
                std::cout << vlt.property.domain << "already has an account with same username\n"; // same domain and username exists
                return false;
            }
        }
        this->vault[vlt.property.domain].push_back(vlt); //domain exists, but username is free
        return true;
    }
    else
    {
        this->vault.emplace(std::make_pair(vlt.property.domain, vlt)); // domain and username free
        return true;
    }
}
void Vault::deleteAccount(const std::string &acct)
{
    // VaultItem vlt = SearchHandler::ReturnReference(acct);
    // PrintHandler::PrintAccount(vlt)
    // Are you sure you want to delete?
    // delete vlt
}
void Vault::modifyAccount(const std::string &acct)
{
    VaultItem *vlt = SearchHandler::ReturnReference(acct);
    PrintHandler::PrintAccount(*vlt);
    std::cout << ""
}