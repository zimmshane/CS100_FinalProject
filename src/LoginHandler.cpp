#include "../include/LoginHandler.hpp"

bool LoginHandler::IsLoginInfoMatchingVault(MasterCredential& master)
{
   // TODO: check config file for credentials under [CURRENT])

   char registerConfirmation;
   std::string hashedUser;
   std::string hashedPass;

   for (;;)
   {
      UserInputHandler::GetMasterInfo(master);
      master.hashed.hashedUserName = CipherHandler::ScryptHashKDF(master.username);
      master.hashed.hashedPassWord = CipherHandler::ScryptHashKDF(master.password);

      // force relogin after register to ensure user input the right information they wanted
      if (!(FileHandler::IsUserVaultExist(master.hashed.hashedUserName))) // if hashed user vault dne
      {
         std::cout << "><>register: \"" << master.username << "\"? (Y/y): ";
         UserInputHandler::GetUpperChar(registerConfirmation);

         if (registerConfirmation == 'Y')
         {
            RegisterVault(master);
         }
      }
      else if (FileHandler::IsVaultPasswordMatch(master))
      {
         return true;
      }
   }

   return false;
}

void LoginHandler::RegisterVault(const MasterCredential& master)
{
   if (!((master.hashed.hashedUserName.empty()) && (master.hashed.hashedPassWord.empty()))) // prevent CTRL+C exit midway of empty password str
   {
      FileHandler::CreateVaultFile(master);
   }

   return;
}