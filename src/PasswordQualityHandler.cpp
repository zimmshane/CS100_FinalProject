#include "../include/PasswordQualityHandler.hpp"
#include "../include/Account.hpp"
#include "../include/Vault.hpp"
#include "../include/SearchHandler.hpp"
/*
    Password Criteria:
    8-32 characters
    contains at least one special symbol, uppercase, and number
*/
bool PasswordQualityHandler::IsPasswordStrong(const std::string& pass) {
    bool containsSymbol = false;
    bool containsUpper = false;
    bool containsNumber = false;

    if(pass.length() > 32 || pass.length() < 8){
        std::cout << "\tpassword length must be [8, 32]\n";
        return false;
    }
    for(unsigned int i = 0; i < pass.length(); i++){
        if(!(isalpha(pass.at(i)) || isdigit(pass.at(i)))){ //special symbol
            containsSymbol = true;
        }
        if(isupper(pass.at(i))){ //uppercase
            containsUpper = true;
        }
        if(isdigit(pass.at(i))){ //number
            containsNumber = true;
        }
    }
    if(containsSymbol == false || containsUpper == false || containsNumber == false){
        std::cout << "\tpassword requires uppercase, digit, and symbol.\n";
        return false;
    }

    return true;
}

//calculates percentage of repetitions
bool PasswordQualityHandler::IsPasswordRepeating(const std::string pass, const Vault& vault) {
    int repeatCounter = 0;
    int length = 0;
    for(auto& entry : vault.vaultContainer){
        for (auto it = entry.second.begin(); it != entry.second.end(); ++it){
            if((*it).password == pass){
                repeatCounter++;
                std::cout << "Repeat password at "<< (*it).username << " in " << (*it).property.domain << "\n";
            }
            length++;

        }
    }
    if(repeatCounter != 0){
        double sum = repeatCounter * 100.0 / length;
        std::cout << "Percentage of repetitions in the vault: " << sum << "%\n";
        return true;
    }
    else{
        std::cout << "No repetitions found" << "\n";
        return false;
    }
    return false;
}