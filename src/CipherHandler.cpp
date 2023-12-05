#include "../include/CipherHandler.hpp"

std::string CipherHandler::ScryptHashKDF(const std::string& inputStr)
{
   std::string defaultSalt {"NaCl OMEGALUL"};

   // std::string --> bytes of data/hex for hashing
   const CryptoPP::byte* passwordBytes {reinterpret_cast<const CryptoPP::byte*>(inputStr.data())};
   const CryptoPP::byte* saltBytes {reinterpret_cast<const CryptoPP::byte*>(defaultSalt.data())};

   // buffer byte block for output of hash (in bytes)
   CryptoPP::SecByteBlock derivedKey(32);

   // instantiate object to utilize class functions
   CryptoPP::Scrypt scrypt;

   // perform key derivation function
   // key size == full .size()
   scrypt.DeriveKey(derivedKey, derivedKey.size(), passwordBytes, inputStr.length(), saltBytes, defaultSalt.length(), 1024, 8, 16);
   // Changing these values change the resulting hash                                 Salt,                          Memory, P, r


   // assign the derived key to a string as an encoded hex string
   // if derived key byte size = 64, then encoded hex str is 128 chars
   // per byte == hex pair
   std::string derivedKeyHexValue;
   CryptoPP::StringSource(derivedKey, derivedKey.size(), true, new CryptoPP::HexEncoder(new CryptoPP::StringSink(derivedKeyHexValue)));

   return derivedKeyHexValue;
}