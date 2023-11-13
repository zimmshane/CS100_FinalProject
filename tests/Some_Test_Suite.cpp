#include  "../include/Vault.hpp"
#include "../include/Account.hpp"
#include  <gtest/gtest.h>

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
v1.deleteAccount(i1.usename);
EXPECT_TRUE(v1.vault[i1.property.domain].size()==1);
}

TEST(VaultTests, canExitDelete){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
Vault v1;
std::stringstream input("n")
v1.addAccount(i1); //will require function to take string stream input
v1.deleteAccount(i1.username,input); //non functional
}

TEST(VaultTests, canModifyAccount){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
std::stringstream input("n");
Vault v1;
v1.addAccount(i1); //non functional
v2.modifyAccount() //will require function to take string stream input
}

TEST(VaultTests, canModifyDomain){
VaultItem i1("jimmy22","LongJohnSilverLUVR","ClubPenguin","Fun game","-f");
Vault v1; //non functional
v1.addAccount(i1)//will require function to take string stream input
}