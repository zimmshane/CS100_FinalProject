#include "../include/FileHandler.hpp"


bool FileHandler::IsUserVaultExist(const std::string &username)
{
   std::string fileName{username + ".vault"};

   std::ifstream iFS{fileName};

   if (iFS.good())
   {
      std::cout << "\tfound: " << fileName << "\n";
      return true;
   }

   std::cout << "\tnot found: " << fileName << "\n";

   return false;
}

void FileHandler::CreateVaultFile(const MasterCredential &master)
{
   std::ofstream oFS{master.hashed.hashedUsername + ".vault"}; // generates .vault file via ofstream

   if (oFS.is_open())
   {
      oFS << master.hashed.hashedPassword << "\n"; // first line is vault password

      // remove this later on, unless for export purposes
      oFS << "username,password,domain,description,tag";

      std::cout << "\tvault sucessfully registered\n";
   }

   return;
}

bool FileHandler::IsVaultPasswordMatch(const MasterCredential &master)
{
   std::ifstream iFS{master.hashed.hashedUsername + ".vault"};
   std::string passwordBuffer;

   if (iFS.is_open())
   {
      std::getline(iFS, passwordBuffer);

      if (passwordBuffer == master.hashed.hashedPassword)
      {
         std::cout << "\tgood vault password hash\n";

         return true;
      }
   }

   std::cout << "\tbad vault password match\n";

   return false;
}

void FileHandler::LoadVaultFile(const std::string& vaultName, Vault& vault)
{
   // logging in already checks file IsUserVaultExist, assume ifstream opens
   std::ifstream iFS{vaultName + ".vault"};

   std::string rawString;
   std::string username;
   std::string password;
   std::string domain;
   std::string description;
   std::string tag;

   // skip first two lines to avoid master password and column parameter
   for (int i = 0; i < 2; ++i)
   {
      std::getline(iFS, rawString);
   }

   while (std::getline(iFS, rawString))
   {
      // load the buffer in new iss
      std::istringstream iSS(rawString);

      // we know there are 5 parameters because we made it up
      // extract per delimiter "comma separated values"
      std::getline(iSS, username, ',');
      std::getline(iSS, password, ',');
      std::getline(iSS, domain, ',');
      std::getline(iSS, description, ',');
      std::getline(iSS, tag, ',');

      vault.vaultContainer[domain].push_back(VaultItem(username, password, domain, description, tag));
   }

   return;
}

void FileHandler::ParseConfig(Config &config,const std::string fileName)
{
   std::ifstream iFS{fileName};
   bool errorFlag = false; // set when error occurs in loading config values into PasswordManager::Config

   if (iFS.good())
   {
      std::string gotLine;
      std::getline(iFS, gotLine);
      if (gotLine == "[GENERATE]") // Verify config file first line correct
      {
         while (std::getline(iFS, gotLine)) // grabs whole lines to pass into lineStream
         {

            if (gotLine == "[CURRENT]") { break; } // Past userconfigs
            std::stringstream lineStream(gotLine);
            std::string parameterName;

            while (std::getline(lineStream, parameterName, '=') && errorFlag == false) // grabs text until '='
            {
               std::string parameterValue;
               std::getline(lineStream, parameterValue); // grabs remainder of line containing value
               if (parameterName == "length")
               {
                  try
                  {
                     config.passwordLength = stoi(parameterValue);
                  }
                  catch (...)
                  {
                     errorFlag = true;
                  }
               }
               else if (parameterName == "alpha")
               {
                  try
                  {
                     config.alphaCount = stoi(parameterValue);
                  }
                  catch (...)
                  {
                     errorFlag = true;
                  }
               }
               else if (parameterName == "numeric")
               {
                  try
                  {
                     config.numberCount = stoi(parameterValue);
                  }
                  catch (...)
                  {
                     errorFlag = true;
                  }
               }
               else if (parameterName == "symbol")
               {
                  try
                  {
                     config.symbolCount = stoi(parameterValue);
                  }
                  catch (...)
                  {
                     errorFlag = true;
                  }
               }
               else
               {
                  errorFlag = true;
               }
            }
         }
      }
   }
   else { errorFlag = true;} //file failed to open

   if((config.alphaCount+config.numberCount+config.symbolCount) != config.passwordLength){ //make sure values sum to length
      errorFlag = true;
   }

   if (errorFlag == true)
   {
      std::cout << "Error Loading Configuration File!\nUsing Default Settings Instead.\n";
      config.passwordLength = 12;
      config.alphaCount = 8;
      config.numberCount = 2;
      config.symbolCount = 2;
      return;
   }
}
void FileHandler::WriteVaultToFile(const MasterCredential& currentUser, const std::unordered_map<std::string, std::vector<VaultItem>>& container)
{
   // BAD: assumes file bit is good from successful vault login access
   std::ofstream oFS{currentUser.hashed.hashedUsername + ".vault"};

   // preprocessing file
   oFS << currentUser.hashed.hashedPassword << "\n";      // look into
   oFS << "username,password,domain,description,tag\n";

   for (const auto& keyIter : container)
   {
      for (const auto& itemVectorIter : keyIter.second)
      {
         oFS << itemVectorIter.username << "," << itemVectorIter.password << "," << itemVectorIter.property.domain << "," << itemVectorIter.property.description << "," << itemVectorIter.property.tag << "\n";
      }
   }
}