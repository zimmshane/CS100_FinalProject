#include "../include/PasswordGenerator.hpp"
#include "../include/Account.hpp"
#include "../include/Vault.hpp"
#include <stdlib.h>
#include <algorithm>

/*
    -Accepted symbols derived from IBM's Business Automation Workflow for
    characters that are valid for passwords
*/
std::string PasswordGenerator::GeneratePassword(){
    const char pass[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!()-.?[]_`~;@#$%^&*+=";
    const int passLength = rand() % 25 + 8;
    std::string generatedPassword = "";
    generatedPassword += pass[std::rand() % 26]; //lowercase
    generatedPassword += pass[std::rand() % 26 + 26]; //upercase
    generatedPassword += pass[std::rand() % 10 + 52]; //numbers
    generatedPassword += pass[std::rand() % 14 + 62]; //lowercase

    for(int i = 4; i < passLength; i++){
        generatedPassword += pass[std::rand() % sizeof(pass)];
    }
    return generatedPassword;
}