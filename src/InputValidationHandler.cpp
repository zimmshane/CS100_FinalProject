#include "../include/InputValidationHandler.hpp"

bool InputValidationHandler::IsUsernameGood(const std::string& username)
{
   std::size_t illegalCharPos;

   if (username.size() == 0)
   {
      std::cout << "username is empty\n";
      return false;
   }
   else if(username.size() > 25 ){
      std::cout << "length of username exceeds the limit of 25 characters\n";
      return false;
   }
   else if (IsContainWhiteSpaceEnds(username))
   {
      return false;
   }
   else if ((illegalCharPos = username.find_first_of("`!@#$%^&*()+=[]{}\\|;:'\",<>?/\t")) != std::string::npos)
   {
      std::cout << "username contains illegal character '" << username[illegalCharPos] << "'\n";
      return false;
   }else if(IsContainComma(username)){
      std::cout << "username can not include commas\n";
      return false;
   }

   return true;
}

bool InputValidationHandler::IsPasswordGood(const std::string& password)
{
   if (password.size() == 0)
   {
      std::cout << "password is empty\n";
      return false;
   }
   else if(password.size() > 25){
      std::cout << "password exceeds the limit of 25 characters\n";
      return false;
   }
   else if (IsContainWhiteSpaceEnds(password))
   {
      return false;
   }
   else if(IsContainComma(password)){
      std::cout << "password can not include commas\n";
      return false;
   }

   return true;
}

// maybe unneeded, create string whitespace trimmer left and right
bool InputValidationHandler::IsContainWhiteSpaceEnds(const std::string& checkStr)
{
   // leading or for empty short circuit
   if (checkStr.empty() || checkStr.front() == ' ' || checkStr.back() == ' ')
   {
      std::cout << "field contains leading or trailing whitespace\n";
      return true;
   }

   return false;
}

bool InputValidationHandler::IsContainComma(const std::string& checkStr){
   if(checkStr.find_first_of(",") == std::string::npos){
      return false;
   }else{
      return true;
   }
}