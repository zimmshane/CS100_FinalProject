#include "../include/PasswordGenerator.hpp"

/*
    -Accepted symbols derived from IBM's Business Automation Workflow for
    characters that are valid for passwords
*/
std::string PasswordGenerator::GeneratePassword(){
    std::ifstream file("./external/dictionary/words.txt");
    std::vector<std::string> wordList;
    std::string word;

    if (!file.is_open())
    {
      std::cout << "Error retrieving word list file!\n";
      return "";
    }
    while(file >> word){
        wordList.push_back(word);
    }

    file.close();

    char pass[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!()-.?[]_`~;@#$%^&*+=";
    int passLength = std::rand() % 5;
    int randomIndex = std::rand() % 150;

    std::string generatedPassword = "";
    generatedPassword += wordList.at(randomIndex);
    generatedPassword += pass[std::rand() % 26]; //lowercase
    generatedPassword += pass[std::rand() % 26 + 26]; //upercase
    generatedPassword += pass[std::rand() % 10 + 52]; //numbers
    generatedPassword += pass[std::rand() % 14 + 62]; //symbols
    for(int i = 0; i < passLength; i++){
        generatedPassword.insert(rand() % generatedPassword.size(), 1, pass[std::rand() % sizeof(pass)]);
    }
    return generatedPassword;
}