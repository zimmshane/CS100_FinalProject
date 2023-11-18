#include "../include/vault.hpp"

bool Vault::addAccount(const VaultItem &vlt)
{
    if (SearchHandler::returnAll(vlt.property.domain))
    { // I'm sure this wont be sufficent to find duplicates
        for (auto it = this->vault[vlt.property.domain].begin(); it != this->vault[vlt.property.domain].end(); ++it)
        {
            if (it->username == vlt.username)
            {
                std::cout << vlt.property.domain << " already has an account with same username\n"; // same domain and username exists don't add
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
   std::string hold;
   VaultItem vlt = SearchHandler::returnAll(acct);
   PrintHandler::PrintAccount(vlt);
   std::cout << "Are you sure you want to delete this account? (y/n)\n";
   std::cin >> hold;
   if (hold == "y" || hold == "Y"){
    if (this->vault[vlt.property.domain].size() == 1){
        this->vault.erase(vlt.property.domain); //if only one username in domain --> delete entire domain
    } 
    else {
        for (auto itr =vault[vlt.property.domain].begin(); itr != vault[vlt.property.domain].end(); itr++ )
            if (itr->username == vlt.username){ // find usernames pos in vector
             this->vault[vlt.property.domain].erase(itr);} // delete spectific vector pos
    }
   }
}
void Vault::modifyAccount(const std::string &acct)
{
    std::vector<VaultItem> vlt = SearchHandler::returnAll(acct);
    PrintHandler::PrintAccount(vlt);

    std::cout<<"Domain: ";
    std::string hold;
    std::cin >> hold;
    if (hold != "" || hold != " "){
        temp.property.domain = hold; // this will likely require deleteaccount() -> addaccount()
    }
   
    std::cout<<"Username: ";
    std::cin >> hold;
    if(hold != "" || hold != " "){
        vlt.username=hold;
    }
    std::cout<<"Password: ";
    std::cin >> hold;
    if(hold != "" || hold != " "){ //this doesnt use whatever password checker function yet
        vlt.password=hold; 
    }
    std::cout<<"Description: ";
    getline(std::cin,hold); 
    if (hold != "" || hold != " "){
        vlt.property.description = hold;
    }
    std::cout<<"Tags: ";
    getline(std::cin,hold); 
    if (hold != "" || hold != " "){
        vlt.property.tag = hold;
    }
}