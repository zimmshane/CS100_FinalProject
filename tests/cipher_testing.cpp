#include <iostream>
#include "../external/cryptopp/scrypt.h"
#include "../external/cryptopp/hex.h"
#include "../external/cryptopp/filters.h"

std::string StringToSHA256(const std::string& input)
{
   std::string defaultSalt {"NaCl OMEGALUL"};

   // std::string --> bytes of data/hex for hashing
   const CryptoPP::byte* pass {reinterpret_cast<const CryptoPP::byte*>(input.data())};
   const CryptoPP::byte* saltBytes {reinterpret_cast<const CryptoPP::byte*>(defaultSalt.data())};

   // buffer byte block for output of hash
   CryptoPP::SecByteBlock derivedKey(32);

   // instantiate object to utilize class functions
   CryptoPP::Scrypt scrypt;

   // perform key derivation function
   scrypt.DeriveKey(derivedKey, derivedKey.size(), pass, input.length(), saltBytes, defaultSalt.length(), 1024, 8, 16);

   // assign the derived key to a string as an encoded hex string
   // if derived key byte size = 64, then derived is 128 hex chars
   // per byte == hex pair
   std::string derivedKeyHexValue;
   CryptoPP::StringSource(derivedKey, derivedKey.size(), true, new CryptoPP::HexEncoder(new CryptoPP::StringSink(derivedKeyHexValue)));

   return derivedKeyHexValue;
}

#include <iostream>

int main()
{
   std::cout << StringToSHA256("my password");

   return 0;
}