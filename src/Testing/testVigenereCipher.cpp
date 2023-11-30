//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("TESTTXTFORCIPHERCIPHERTESTFORMPAGSCIPHER", CipherMode::Encrypt) == "BJEFIFYRAGKNBTTZHUBWMWFQHBKADBXFSERQUTQG");
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("BJEFIFYRAGKNBTTZHUBWMWFQHBKADBXFSERQUTQG", CipherMode::Decrypt) == "TESTTXTFORCIPHERCIPHERTESTFORMPAGSCIPHER");
}