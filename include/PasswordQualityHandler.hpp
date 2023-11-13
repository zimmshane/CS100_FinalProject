#ifndef PASSWORDQUALITYHANDLER_HPP
#define PASSWORDQUALITYHANDLER_HPP

class PasswordQualityHandler {
    public:
        bool StrengthChecker(const std::string&);
        bool RepeatChecker(const std::string&);
};

#endif // !PASSWORDQUALITYHANDLER_HPP
