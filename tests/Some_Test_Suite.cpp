#include "../include/PasswordQualityHandler.hpp"
#include "../external/googletest/googletest/include/gtest/gtest.h"
#include "../include/FileHandler.hpp"
#include "../include/InputValidationHandler.hpp"
#include "../include/LoginHandler.hpp"
#include "../include/PasswordManager.hpp"
#include "../include/UserInputHandler.hpp"
#include "../include/Vault.hpp"

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
   EXPECT_FALSE(PasswordQualityHandler::StrengthChecker("2short"));
   EXPECT_FALSE(PasswordQualityHandler::StrengthChecker("notacceptablecuzalllower"));
   EXPECT_FALSE(PasswordQualityHandler::StrengthChecker("NOTACCEPTABLECUZALLUPPER"));
   EXPECT_FALSE(PasswordQualityHandler::StrengthChecker("!@#$%^&****"));
   EXPECT_FALSE(PasswordQualityHandler::StrengthChecker("DoesnthaveSymbol1"));

}

TEST(PasswordQualityTests, verifyValidPasswords)
{
   EXPECT_TRUE(PasswordQualityHandler::StrengthChecker("H3LLoT4ere!"));
   EXPECT_TRUE(PasswordQualityHandler::StrengthChecker("#Th1sworks"));
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
