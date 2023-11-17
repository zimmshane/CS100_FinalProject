#ifndef INPUTVALIDATIONHANDLER_HPP
#define INPUTVALIDATIONHANDLER_HPP

#include <iostream>

class InputValidationHandler
{
public:
   static bool IsMasterUsernameGood(const std::string& username);
   static bool IsMasterPasswordGood(const std::string& password);
};

#endif // !INPUTVALIDATIONHANDLER_HPP
