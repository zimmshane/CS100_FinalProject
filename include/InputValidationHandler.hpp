#ifndef INPUTVALIDATIONHANDLER_HPP
#define INPUTVALIDATIONHANDLER_HPP

#include <iostream>

class InputValidationHandler
{
public:
   static bool IsUsernameGood(const std::string& username);
   static bool IsPasswordGood(const std::string& password);
   static bool IsContainWhiteSpaceEnds(const std::string& string);
   static bool IsContainComma(const std::string& string);

};

#endif // !INPUTVALIDATIONHANDLER_HPP
