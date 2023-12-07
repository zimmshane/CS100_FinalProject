#include "../include/PasswordQualityHandler.hpp"
#include "../external/googletest/googletest/include/gtest/gtest.h"
#include "../include/FileHandler.hpp"
#include "../include/InputValidationHandler.hpp"
#include "../include/LoginHandler.hpp"
#include "../include/PasswordManager.hpp"
#include "../include/UserInputHandler.hpp"
#include "../include/Vault.hpp"
#include "../include/PasswordGenerator.hpp"
#include <iostream>
#include <string>
#include "../include/CipherHandler.hpp"

TEST(ItemContainerTests, VerifyValues)
{
   VaultItem item("JohnDoe832", "Doughy$1332", "amazon", "this account has prime", "-p");

   EXPECT_EQ(item.username, "JohnDoe832");
   EXPECT_EQ(item.password, "Doughy$1332");
   EXPECT_EQ(item.property.domain, "amazon");
   EXPECT_EQ(item.property.description, "this account has prime");
   EXPECT_EQ(item.property.tag, "-p");
}

TEST(ItemContainerTests, VerifySpecialValues) // constructor can take anything, but the user inputs shouldn't
{
   VaultItem item("^&^JohnDoe0", "Choco%/late#Fudge!@1911", "discord", "for school use", "-p");

   EXPECT_EQ(item.username, "^&^JohnDoe0");
   EXPECT_EQ(item.password, "Choco%/late#Fudge!@1911");
   EXPECT_EQ(item.property.domain, "discord");
   EXPECT_EQ(item.property.description, "for school use");
   EXPECT_EQ(item.property.tag, "-p");
}

TEST(VaultEntityTests, FindVault)
{
   EXPECT_FALSE(FileHandler::IsUserVaultExist("someuservault.vault"));
}

TEST(IllegalUsernameTests, LeadingSpaces)
{
   EXPECT_FALSE(InputValidationHandler::IsUsernameGood("    this string has leading space"));
}

TEST(IllegalUsernameTests, ContainingCommas)
{
   EXPECT_FALSE(InputValidationHandler::IsUsernameGood("    this,, string includes commas,,"));
}

TEST(IllegalUsernameTests, BigUsernameSize)
{
   EXPECT_FALSE(InputValidationHandler::IsUsernameGood("thisusernameisover 25 characters long"));
}

TEST(IllegalUsernameTests, TrailingSpaces)
{
   EXPECT_FALSE(InputValidationHandler::IsUsernameGood("this string has a trailing space "));
}

TEST(IllegalUsernameTests, SpecialCharacters)
{
   EXPECT_FALSE(InputValidationHandler::IsUsernameGood("this character has !some special character"));
}

TEST(IllegalPasswordTests, LeadingSpace)
{
   EXPECT_FALSE(InputValidationHandler::IsPasswordGood(" this string has a leading space"));

}

TEST(IllegalPasswordTests, BigPasswordSize)
{
   EXPECT_FALSE(InputValidationHandler::IsPasswordGood(" thisstringisover25characterslong"));

}

TEST(IllegalPasswordTests, ContainingCommas)
{
   EXPECT_FALSE(InputValidationHandler::IsPasswordGood(" this,, string,, has a comma"));

}

TEST(IllegalPasswordTests, TrailingSpace)
{
   EXPECT_FALSE(InputValidationHandler::IsPasswordGood("this string has a leading space   has many !! ##!@# trailing spaces     "));
}

TEST(PasswordQualityTests, invalidPasswords)
{
   EXPECT_FALSE(PasswordQualityHandler::IsPasswordStrong("2short"));
   EXPECT_FALSE(PasswordQualityHandler::IsPasswordStrong("notacceptablecuzalllower"));
   EXPECT_FALSE(PasswordQualityHandler::IsPasswordStrong("NOTACCEPTABLECUZALLUPPER"));
   EXPECT_FALSE(PasswordQualityHandler::IsPasswordStrong("!@#$%^&****"));
   EXPECT_FALSE(PasswordQualityHandler::IsPasswordStrong("DoesnthaveSymbol1"));

}

TEST(PasswordQualityTests, verifyValidPasswords)
{
   EXPECT_TRUE(PasswordQualityHandler::IsPasswordStrong("H3LLoT4ere!"));
   EXPECT_TRUE(PasswordQualityHandler::IsPasswordStrong("#Th1sworks"));
}


TEST(ImportConfigTests, canHandleMissingValues){
   std::ofstream genconfig("TESTconfig.txt");
   genconfig<<"[GENERATE]\nlength=16\nsymbol=4\n[CURRENT]";
   genconfig.close();
   Config testConfig;
   FileHandler::ParseConfig(testConfig,"TESTconfig.txt");
   EXPECT_TRUE(testConfig.alphaCount==8);
   EXPECT_TRUE(testConfig.passwordLength==12);
   EXPECT_TRUE(testConfig.numberCount==2);
   EXPECT_TRUE(testConfig.symbolCount==2);


}
TEST(ImportConfigTests, canHandleNonNumber){
   std::ofstream genconfig("TESTconfig.txt");
   genconfig<<"[GENERATE]\nlength=16\nalpha=NOTANUMBER\nnumeric=3\nsymbol=4\n[CURRENT]";
   genconfig.close();
   Config testConfig;
   FileHandler::ParseConfig(testConfig,"TESTconfig.txt");
   EXPECT_TRUE(testConfig.alphaCount==8);
   EXPECT_TRUE(testConfig.passwordLength==12);
   EXPECT_TRUE(testConfig.numberCount==2);
   EXPECT_TRUE(testConfig.symbolCount==2);
}
TEST(ImportConfigTests, canHandleBadMath){
   std::ofstream genconfig("TESTconfig.txt");
   genconfig<<"[GENERATE]\nlength=16\nalpha=24\nnumeric=45\nsymbol=4\n[CURRENT]";
   genconfig.close();
   Config testConfig;
   FileHandler::ParseConfig(testConfig,"TESTconfig.txt");
   EXPECT_TRUE(testConfig.alphaCount==8);
   EXPECT_TRUE(testConfig.passwordLength==12);
   EXPECT_TRUE(testConfig.numberCount==2);
   EXPECT_TRUE(testConfig.symbolCount==2);
}
TEST(ImportConfigTests, canHandleNoFile){
   Config testConfig;
   FileHandler::ParseConfig(testConfig,"THISFILEDOESNTEXIST.txt");
   EXPECT_TRUE(testConfig.alphaCount==8);
   EXPECT_TRUE(testConfig.passwordLength==12);
   EXPECT_TRUE(testConfig.numberCount==2);
   EXPECT_TRUE(testConfig.symbolCount==2);
}

TEST(ImportConfigTests, canImportConfig){
   std::ofstream genconfig("TESTconfig.txt");
   genconfig<<"[GENERATE]\nlength=16\nalpha=9\nnumeric=3\nsymbol=4\n[CURRENT]";
   genconfig.close();
   Config testConfig;
   FileHandler::ParseConfig(testConfig,"TESTconfig.txt");
   EXPECT_EQ(testConfig.alphaCount,9);
   EXPECT_EQ(testConfig.passwordLength,16);
   EXPECT_EQ(testConfig.numberCount,3);
   EXPECT_EQ(testConfig.symbolCount,4);}

TEST(PasswordQualityTests, randomPasswordIsValid)
{
   std::string pass = PasswordGenerator::GeneratePassword();
   EXPECT_TRUE(PasswordQualityHandler::IsPasswordStrong(pass));

}

TEST(PasswordQualityTests, randomPasswordsAreDiff)
{
   std::string pass = PasswordGenerator::GeneratePassword();
   std::string pass2 = PasswordGenerator::GeneratePassword();
   std::string pass3 = PasswordGenerator::GeneratePassword();
   EXPECT_NE(pass, pass2);
   EXPECT_NE(pass, pass3);
   EXPECT_NE(pass3, pass2);

}

TEST(StringContainsComma, validStringInput)
{
   EXPECT_TRUE(InputValidationHandler::IsContainComma(",Hello1234"));
   EXPECT_TRUE(InputValidationHandler::IsContainComma("Hiii,000,"));
}

TEST(StringContainsComma, invalidStringInput)
{
   EXPECT_FALSE(InputValidationHandler::IsContainComma("Hello1234"));
   EXPECT_FALSE(InputValidationHandler::IsContainComma("JoeDoe 689"));

}

TEST(StringContainWhiteSpaceEnds, emptyString)
{
   bool falseOutput = InputValidationHandler::IsContainWhiteSpaceEnds(" ");
   EXPECT_TRUE(falseOutput);
}

TEST(StringContainWhiteSpaceEnds, noWhiteSpaces)
{
   EXPECT_FALSE(InputValidationHandler::IsContainWhiteSpaceEnds("JoeDoe158"));
   EXPECT_FALSE(InputValidationHandler::IsContainWhiteSpaceEnds("Bob1257"));
}

TEST(StringContainWhiteSpaceEnds, inValidStrings)
{
   EXPECT_TRUE(InputValidationHandler::IsContainWhiteSpaceEnds("JoeDoe158 "));
   EXPECT_TRUE(InputValidationHandler::IsContainWhiteSpaceEnds(" Bob1257"));
   EXPECT_TRUE(InputValidationHandler::IsContainWhiteSpaceEnds(" Sandra8903 "));
}

TEST(AddItem, item_EmptyVault){
   VaultItem item("JohnDoe832", "Doughy$1332", "amazon", "this account has prime", "-p");
   Vault userVault;
   bool isTrue = userVault.AddItem(item);
   EXPECT_TRUE(isTrue);
}

TEST(AddItem, duplicateItem_Vault){
   VaultItem item("JohnDoe832", "Doughy$1332", "amazon", "this account has prime", "-p");
   Vault userVault;
   bool isTrue = userVault.AddItem(item);
   isTrue = userVault.AddItem(item);
   EXPECT_FALSE(isTrue);
}

TEST(AddItem, differentItems_Vault){
   VaultItem item("JohnDoe832", "Doughy$1332", "amazon", "this account has prime", "-p");
   VaultItem item1("JohnDoe832", "Doughy$1332", "bestbuy", "this account has best buy", "-b");
   Vault userVault;
   bool isTrue = userVault.AddItem(item);
   isTrue = userVault.AddItem(item1);
   EXPECT_TRUE(isTrue);
}

TEST(IsUsernameExistInDomainVector, emptyVector){
   std::vector<VaultItem> itemVector;
   bool falseOutput = SearchHandler::IsUsernameExistInDomainVector("", itemVector);
   EXPECT_FALSE(falseOutput);
}

TEST(IsUsernameExistInDomainVector, usernameExists){
   std::vector<VaultItem> itemVector;
   VaultItem item("JohnDoe832", "Doughy$1332", "amazon", "this account has prime", "-p");
   itemVector.push_back(item);
   bool trueOutput = SearchHandler::IsUsernameExistInDomainVector("JohnDoe832", itemVector);
   EXPECT_TRUE(trueOutput);
}

TEST(IsUsernameExistInDomainVector, noExistingUsername){
   std::vector<VaultItem> itemVector;
   VaultItem item("JohnDoe832", "Doughy$1332", "amazon", "this account has prime", "-p");
   VaultItem item1("MaryJohn156", "JJMon876$9", "bestbuy", "this account has best buy", "-b");
   itemVector.push_back(item);
   itemVector.push_back(item1);
   bool falseOutput = SearchHandler::IsUsernameExistInDomainVector("JohnDoe8442", itemVector);
   EXPECT_FALSE(falseOutput);
}

TEST(SearchDuplicate, emptyVault){
   Vault userVault;
   bool falseOutput = SearchHandler::SearchDuplicate("JohnDoe8442", userVault);
   EXPECT_FALSE(falseOutput);
}

TEST(SearchDuplicate, duplicateDomains){
   Vault userVault;
   std::unordered_map<std::string, std::vector<VaultItem>> vaultContainer;
   VaultItem item("JohnDoe832", "Doughy$1332", "amazon", "this account has prime", "-p");
   VaultItem item1("JohnDoe832", "JJMon876$9", "amazon", "this account has prime", "-p");
   userVault.vaultContainer[item.property.domain].push_back(item);
   userVault.vaultContainer[item1.property.domain].push_back(item1);
   bool trueOutput = SearchHandler::SearchDuplicate("amazon", userVault);
   EXPECT_TRUE(trueOutput);
}

TEST(SearchDuplicate, noDuplicateDomains){
   Vault userVault;
   std::unordered_map<std::string, std::vector<VaultItem>> vaultContainer;
   VaultItem item("JohnDoe832", "Doughy$1332", "amazon", "this account has prime", "-p");
   VaultItem item1("JohnDoe832", "JJMon876$9", "bestBuy", "this account has electronics", "-b");
   userVault.vaultContainer[item.property.domain].push_back(item);
   userVault.vaultContainer[item1.property.domain].push_back(item1);
   bool falseOutput = SearchHandler::SearchDuplicate("walmart", userVault);
   EXPECT_FALSE(falseOutput);
}

// if any of these go bad, that means the hash value has changed
TEST(CipherHandlerScryptHash, BasicString)
{
   std::string myHash {CipherHandler::ScryptHashKDF("Mypasswordstring")};
   ASSERT_EQ(myHash, "D9A174BF421E24AA5C3D8BF67DFA0F7B8B5DB964F77BE4B8CED14FFB236F3440");
}

TEST(CipherHandlerScryptHash, StrongPasswordString)
{
   std::string myHash {CipherHandler::ScryptHashKDF("SomepasswordString##!9230$")};
   ASSERT_EQ(myHash, "985C4DB0EDC3F113F92356CA9CB4E362DD94E02E4604D9083A48D553FF768F68");
}

TEST(CipherHandlerScryptHash, ZeroLiteralString)
{
   std::string myHash {CipherHandler::ScryptHashKDF("0")};
   ASSERT_EQ(myHash, "ACB8301CED5B38329141912D80C19191E8DA735875DAA0B41DF231800255A0EF");
}

TEST(CipherHandlerScryptHash, EmptyString)
{
   std::string myHash {CipherHandler::ScryptHashKDF("")};
   ASSERT_EQ(myHash, "9A118D5C3A9B67480ED0A02B357BF1FD8254FFF82D4FC6E66E36999C74DADCB0");
}
