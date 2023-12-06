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

    const char pass[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!()-.?[]_`~;@#$%^&*+=";
    const int passLength = rand() % 12 + 8;
    const int randomIndex = rand() % 150;

    std::string generatedPassword = "";
    generatedPassword += pass[std::rand() % 26]; //lowercase
    generatedPassword += pass[std::rand() % 26 + 26]; //upercase
    generatedPassword += pass[std::rand() % 10 + 52]; //numbers
    generatedPassword += pass[std::rand() % 14 + 62]; //lowercase
    generatedPassword += wordList.at(randomIndex);
    for(int i = 4; i < passLength; i++){
        generatedPassword += pass[std::rand() % sizeof(pass)];
    }
    return generatedPassword;
}