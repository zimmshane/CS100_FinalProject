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
        return false;
    }
    return true;
}

//calculates percentage of repetitions
bool PasswordQualityHandler::IsPasswordRepeating(const std::string pass, const Vault& vault) {
    while(SearchHandler::SearchDuplicatePassword(pass, vault)){

    }
    return false;
}