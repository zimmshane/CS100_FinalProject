#include <iostream>
#include "../include/PasswordQualityHandler.hpp"
#include <string>
/*
    Password Criteria:
    8-32 characters
    contains at least one special symbol, uppercase, and number
*/
bool PasswordQualityHandler::StrengthChecker(const std::string& str) {
    bool containsSymbol = false;
    bool containsUpper = false;
    bool containsNumber = false;
    if(str.length() > 32 || str.length() < 8){
        return false;
    }
    for(unsigned int i = 0; i < str.length(); i++){
        if(!(isalpha(str.at(i)) || isdigit(str.at(i)))){ //special symbol
            containsSymbol == true;
        }
        if(isupper(str.at(i))){ //uppercase
            containsUpper == true;
        }
        if(isdigit(str.at(i))){ //number
            containsNumber == true;
        }
    }
    if(containsSymbol == false || containsUpper == false || containsNumber == false){
        return false;
    }
    return true;
}
bool PasswordQualityHandler::RepeatChecker(const std::string&) {

}