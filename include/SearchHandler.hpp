#ifndef SEARCHHANDLER_HPP
#define SEARCHHANDLER_HPP
#include "Account.hpp"

class SearchHandler {
    public:
        void Search(const std:: string&);
        void Search(const std:: string&, const std::string&);
        bool SearchDuplicate(const std:: string&);
        int SearchSubstring(const std::string&, int);
        VaultItem& ReturnReference(const std::string&);
};

#endif // !SEARCHHANDLER_HPP