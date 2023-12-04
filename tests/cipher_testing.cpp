#include <iostream>
#include "../external/cryptopp/scrypt.h"
#include "../external/cryptopp/hex.h"
#include "../external/cryptopp/filters.h"

std::string StringToSHA256(const std::string& input)
{
   std::string defaultSalt {"NaCl OMEGALUL"};

   // std::string --> bytes of data/hex for hashing
   const CryptoPP::byte* pass = reinterpret_cast<const CryptoPP::byte*>(input.data());
   const CryptoPP::byte* saltBytes = reinterpret_cast<const CryptoPP::byte*>(defaultSalt.data());

   // buffer byte block for output of hash
   CryptoPP::SecByteBlock derivedKey(64);

   // instantiate object to utilize class functions
   CryptoPP::Scrypt scrypt;

   // perform key derivation function
   scrypt.DeriveKey(derivedKey, derivedKey.size(), pass, input.length(), saltBytes, defaultSalt.length(), 1024, 8, 16);

   // Convert the derived key to a hexadecimal string
   std::string hexDerived;
   CryptoPP::StringSource(derivedKey, 16, true, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hexDerived)));

   return hexDerived;
}

#include <iostream>

int main()
{
   std::cout << StringToSHA256("my password");

   return 0;
}