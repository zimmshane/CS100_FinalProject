#include "../include/InputValidationHandler.hpp"


bool InputValidationHandler::IsUsernameBad(const std::string& username)
{
   if ((username.front() == ' ') || (username.back()) == ' ')
   {
      std::cerr << "username contains leading or trailing whitespace\n";
      return true;
   }
   else if (username.find('#'))
   {
      std::cout << username[username.find('#')];
   }
}
