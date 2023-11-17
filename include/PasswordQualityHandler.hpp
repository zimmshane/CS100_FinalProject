#ifndef PASSWORDQUALITYHANDLER_HPP
#define PASSWORDQUALITYHANDLER_HPP
#include <string>
#include "Account.hpp"

class PasswordQualityHandler {
    public:
        static bool StrengthChecker(const std::string& pass);
        static bool RepeatChecker(const std::string& pass);
};

#endif // !PASSWORDQUALITYHANDLER_HPP
