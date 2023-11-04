#include <iostream>
#include "../include/Account.hpp"

int main(int argc, char* argv[])
{
   MasterCredentials loggedUser("initialUser", "initialPass");
   std::cout << loggedUser.username << " " << loggedUser.password << "\n";





   return 0;
}