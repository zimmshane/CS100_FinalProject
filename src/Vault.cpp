#include "../include/Vault.hpp"

bool Vault::addAccount(const VaultItem &vlt)
{
    if (SearchHandler::returnAll(vlt.property.domain,*this).size()==0) // domain not in list
    { 
        for (auto it = this->vault[vlt.property.domain].begin(); it != this->vault[vlt.property.domain].end(); ++it)
        {
            if (it->username == vlt.username)
            {
                std::cout << vlt.property.domain << " already has an account with same username\n"; // same domain and username exists don't add
                return false;
            }
        } 
    } 
        this->vault[vlt.property.domain].push_back(vlt); // domain and username free
        return true;
}
void Vault::deleteAccount(const std::string &acct)
{ 
    VaultItem target = Vault::findFromSearch(acct);
    std::string input = "";
    input = UserInputHandler::getStringInput("Are you sure you want to delete this account? (y/n) ");
   if (input == "y" || input == "Y"){
        forceDeleteAccount(target);
        std::cout<<"Account Deleted.\n";}
    else{
        std::cout << "Account Deletion Aborted.\n";
    }
}
void Vault::forceDeleteAccount(const VaultItem& target) {
if (this->vault[target.property.domain].size() == 1){
    this->vault.erase(target.property.domain); //if only one username in domain --> delete entire domain
    } 
if (this->vault[target.property.domain].size()==0){
     std::cout << "Account Deletion Failed\n";
     return;
    }
    else {
     std::vector<VaultItem>::iterator it = Vault::getPositionedItr(target);
     this->vault[target.property.domain].erase(it);} // delete spectific vector pos
   
}


void Vault::modifyAccount(const std::string &acct)
{

    VaultItem target = Vault::findFromSearch(acct); //
    std::vector<VaultItem>::iterator it = Vault::getPositionedItr(target);

    std::string input;
    input=UserInputHandler::getStringInput("Domain: ");
    if (!input.empty() && input != " "){
        forceDeleteAccount(target);
        target.property.domain=input;
        this->vault[input].push_back(target);
        it = Vault::getPositionedItr(target);
    }
    
    input= UserInputHandler::getStringInput("Username: ");
    if(!input.empty() && input != " "){
        it->username=input;
    }

    input= UserInputHandler::getStringInput("Password: ");
    if(!input.empty() && input != " "){ //this doesnt use whatever password checker function yet
        it->password=input; 
    }

    input = UserInputHandler::getStringInput("Description: ");
    if (!input.empty() && input != " "){
        it->property.description = input;
    }
    input =UserInputHandler::getStringInput("Tags: ");
    if (!input.empty() && input != " "){
        it->property.tag = input;
    }

    PrintHandler::printVaultItem(*it);
}

VaultItem Vault::findFromSearch(const std::string& search){

   std::vector<VaultItem> vltlist = SearchHandler::returnAll(search,*this);
   PrintHandler::printVector(vltlist);

   std::cout << "Input the number for the item you're interested in: " ;
   int indexin = 0;
   std::cin >> indexin; //TODO: Validate this input
   VaultItem target = vltlist.at(indexin-1);
   PrintHandler::printVaultItem(target);
   return target;
}
std::vector<VaultItem>::iterator Vault::getPositionedItr(const VaultItem& target){
    auto it = this->vault[target.property.domain].begin();
    for (; it != this->vault[target.property.domain].end(); ++it){
        if (it->username == target.username) break;
    }
    return it;
}

