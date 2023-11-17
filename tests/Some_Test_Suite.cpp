#include "../external/googletest/googletest/include/gtest/gtest.h"
#include "../include/PasswordQualityHandler.hpp"
#include "../src/PasswordQualityHandler.cpp"
#include "../include/Vault.hpp"

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

