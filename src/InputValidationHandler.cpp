#include "../include/InputValidationHandler.hpp"

bool InputValidationHandler::IsMasterUsernameGood(const std::string& username)
{
   std::size_t illegalCharPos;

   if (username.size() == 0)
   {
      std::cout << "username is empty\n";
      return false;
   }
   else if (IsEndsWhiteSpace(username))
   {
      std::cout << "username contains leading or trailing whitespace\n";
      return false;
   }
   else if ((illegalCharPos = username.find_first_of("`!@#$%^&*()+=[]{}\\|;:'\",<>?/\t")) != std::string::npos)
   {
      std::cout << "username contains illegal character '" << username[illegalCharPos] << "'\n";
      return false;
   }

   return true;
}

bool InputValidationHandler::IsMasterPasswordGood(const std::string& password)
{
   if (password.size() == 0)
   { // do we really care about an empty password thhough?
      std::cout << "password is empty\n";
      return false;
   }
   else if (IsEndsWhiteSpace(password))
   {
      std::cout << "password contains leading or trailing whitespace\n";
      return false;
   }

   return true;
}

bool InputValidationHandler::IsEndsWhiteSpace(const std::string& checkStr)
{
   if (checkStr.front() == ' ' || checkStr.back() == ' ')
   {
      return true;
   }

   return false;
}