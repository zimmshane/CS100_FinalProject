#ifndef INPUTVALIDATIONHANDLER_HPP
#define INPUTVALIDATIONHANDLER_HPP

#include <iostream>

class InputValidationHandler
{
public:
   static bool IsMasterUsernameBad(const std::string& username);
   static bool IsMasterPasswordBad(const std::string& password);

};

#endif // !INPUTVALIDATIONHANDLER_HPP
