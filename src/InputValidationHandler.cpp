#include "../include/InputValidationHandler.hpp"


bool InputValidationHandler::IsMasterUsernameBad(const std::string& username)
{
   std::size_t illegalCharPos;

   if ((username.front() == ' ') || (username.back()) == ' ')
   {
      std::cerr << "username contains leading or trailing whitespace\n";
      return true;
   }
   else if ((illegalCharPos = username.find_first_of("`!@#$%^&*()+=[]{}\\|;:'\",<>?/")) != std::string::npos)
   {
      std::cerr << "username contains illegal character '" << username[illegalCharPos] << "'\n";
      return true;
   }

   return false;
}

bool InputValidationHandler::IsMasterPasswordBad(const std::string& password)
{
   if ((password.front() == ' ') || (password.back()) == ' ')
   {
      std::cerr << "password contains leading or trailing whitespace\n";
      return true;
   }

   return false;
}
