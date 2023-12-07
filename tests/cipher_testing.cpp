#include <iostream>
#include "../include/CipherHandler.hpp"

#include <iostream>

int main()
{
   std::cout << CipherHandler::ScryptHashKDF("Mypasswordstring") << "\n"; // unsafepassword
   std::cout << CipherHandler::ScryptHashKDF("SomepasswordString##!9230$") << "\n"; // safe password
   std::cout << CipherHandler::ScryptHashKDF("0") << "\n"; // literal 0
   std::cout << CipherHandler::ScryptHashKDF("") << "\n"; // empty string



   return 0;
}