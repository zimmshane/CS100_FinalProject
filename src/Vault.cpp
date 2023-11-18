#include "../include/Vault.hpp"

bool Vault::addAccount(const VaultItem&){
    return true;
}

void Vault::deleteAccount(const std::string&){
    std::cout << "Testing delete\n";
}

void Vault::modifyAccount(const std::string&){
    std::cout << "Testing modify\n";
}
