#include "../external/googletest/googletest/include/gtest/gtest.h"
#include "../include/Vault.hpp"
#include "../include/FileHandler.hpp"


TEST(ItemContainerTests, VerifyValues)
{
   VaultItem item("JohnDoe832", "Doughy$1332", "amazon", "this account has prime", "-p");

   EXPECT_EQ(item.username, "JohnDoe832");
   EXPECT_EQ(item.password, "Doughy$1332");
   EXPECT_EQ(item.property.domain, "amazon");
   EXPECT_EQ(item.property.description, "this account has prime");
   EXPECT_EQ(item.property.tag, "-p");
}

TEST(ItemContainerTests, VerifySpecialValues)
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