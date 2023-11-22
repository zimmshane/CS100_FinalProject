#ifndef INPUTVALIDATIONHANDLER_HPP
#define INPUTVALIDATIONHANDLER_HPP

#include <iostream>

class InputValidationHandler
{
public:
   static bool IsMasterUsernameGood(const std::string& username);
   static bool IsMasterPasswordGood(const std::string& password);
   static bool IsItemUsernameGood(const std::string& username);
   static bool IsItemUsernamePassword(const std::string& username);
   static bool IsContainWhiteSpaceEnds(const std::string& string);
};

#endif // !INPUTVALIDATIONHANDLER_HPP
