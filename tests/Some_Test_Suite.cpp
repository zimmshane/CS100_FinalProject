#include "../include/Account.hpp"
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
   EXPECT_FALSE(InputValidationHandler::IsMasterUsernameGood("    this string has leading space"));
}

TEST(IllegalUsernameTests, TrailingSpaces)
{
   EXPECT_FALSE(InputValidationHandler::IsMasterUsernameGood("this string has a trailing space "));
}

TEST(IllegalUsernameTests, SpecialCharacters)
{
   EXPECT_FALSE(InputValidationHandler::IsMasterUsernameGood("this character has !some special character"));
}

TEST(IllegalPasswordTests, LeadingSpace)
{
   EXPECT_FALSE(InputValidationHandler::IsMasterPasswordGood(" this string has a leading space"));

}

TEST(IllegalPasswordTests, TrailingSpace)
{
   EXPECT_FALSE(InputValidationHandler::IsMasterPasswordGood("this string has a leading space   has many !! ##!@# trailing spaces     "));
}
TEST(VaultTests, canAddAccount){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
Vault v1;
v1.addAccount(i1);
EXPECT_EQ(v1.vault[i1.property.domain].at(0).username,i1.username);

}
TEST(VaultTests, canAddSameDomainAccount){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
VaultItem i2("jimmy22","LongJohnSilverHATER","ClubPenguin","Fun game","-f");
Vault v1;
v1.addAccount(i1);
v1.addAccount(i2);
EXPECT_TRUE(v1.vault[i1.property.domain].at(1).username,i2.username)
}

TEST(VaultTests, canNOTAddDuplicateAccount){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
Vault v1;
v1.addAccount(i1);
EXPECT_FALSE(v1.addAccount(v1));
EXPECT_TRUE(v1.vault[i1.property.domain].size()==1);
}

TEST(VaultTests, canDeleteAccount){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
VaultItem i2("jimmy22","LongJohnSilverHATER","ClubPenguin","Fun game","-f");
Vault v1;

v1.addAccount(i1);
v1.addAccount(i2);
EXPECT_TRUE(v1.vault[i1.property.domain].size()==2);
v1.deleteAccount(i1.username);
EXPECT_TRUE(v1.vault[i1.property.domain].size()==1);
}

TEST(VaultTests, canExitDelete){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
Vault v1;
std::stringstream input("n");
v1.addAccount(i1); //will require function to take string stream input
v1.deleteAccount(i1.username,input); //non functional
}

TEST(VaultTests, canModifyAccount){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
std::stringstream input("n");
Vault v1;
v1.addAccount(i1); //non functional
v1.modifyAccount(); //will require function to take string stream input
}

TEST(VaultTests, canModifyDomain){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
Vault v1; //non functional
v1.addAccount(i1);  //will require function to take string stream input