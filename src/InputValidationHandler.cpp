#include "../include/InputValidationHandler.hpp"

bool InputValidationHandler::IsMasterUsernameGood(const std::string& username)
{
   std::size_t illegalCharPos;

   if ((username.front() == ' ') || (username.back()) == ' ')
   {
      std::cout << "username contains leading or trailing whitespace\n";
      return false;
   }
   else if ((illegalCharPos = username.find_first_of("`!@#$%^&*()+=[]{}\\|;:'\",<>?/")) != std::string::npos)
   {
      std::cout << "username contains illegal character '" << username[illegalCharPos] << "'\n";
      return false;
   }

   return true;
}

bool InputValidationHandler::IsMasterPasswordGood(const std::string& password)
{
   if ((password.front() == ' ') || (password.back()) == ' ')
   {
      std::cout << "password contains leading or trailing whitespace\n";
      return false;
   }

   return true;
}
