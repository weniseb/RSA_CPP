//---------------------------------------------------------
// Main class for RSA de-/encprytion.
//
// Author: Sebastian Weninger
//

#ifndef RSA_
#define RSA_

#include <ostream>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using std::string;

namespace Crypto
{
  typedef std::vector<int256_t> CryptoString; // To store encrypted chars
  typedef int256_t CryptoChar; // To store encrypted chars

  // struct to hold private key members
  typedef struct
  {
    int256_t s;
    int256_t p;
    int256_t q;
  } PrivateKey;

  // struct to hold public key members
  typedef struct
  {
    int256_t r;
    int256_t m;
  } PublicKey;

  class RSA
  {
  private:

    // PRIVATE KEY MEMBERS
    int256_t p;
    int256_t q;
    int256_t phi_of_m;

    //PUBLIC KEY MEMBERS
    int256_t m;
    int256_t r;

    PrivateKey* private_key;
    PublicKey* public_key;

    void calcPublicKey();
    void calcPrivateKey();

    int256_t makePositive(int256_t numb, int256_t mod) const;

    //-----------------------------------------------------
    // Set class members for calculating the private and
    // public key.
    //
    // int256_t p: First prime number (has to be prime)
    // int256_t q: Second prime number (has to be prime)
    // int256_t r: public key member (gcd of 'r' and 'p * q' must be 1)
    void setParameters(int256_t p, int256_t q, int256_t r);

    //-----------------------------------------------------
    // Calculate private and public key. (Only if class
    // members are set previously)
    //
    void calcKeys();

    //-----------------------------------------------------
    // Checks if given number is a prime number.
    //
    // int256_t numb: number to check
    // return: true if it is prime; false if not
    static bool isPrime(int256_t numb);

    //-----------------------------------------------------
    // Calculate phi of two prime numbers
    //
    // int a: first prime number
    // int b: second prime number
    // return: phi of m
    static int256_t calcPhi(int256_t a, int256_t b);

  public:
    RSA() = delete;

    //-----------------------------------------------------
    // Constructor
    //
    // int256_t p: First prime number
    // int256_t q: Second prime number
    // int256_t r: First public-key member
    //
    // Important: r must be coprime with phi of m!
    //            r also must be equal or less than phi of m!
    //            p and q must be prime numbers!
    //
    RSA(int256_t p, int256_t q, int256_t r);

    //-----------------------------------------------------
    // return: const pointer to public key
    const PublicKey* getPublicKey() const;

    //-----------------------------------------------------
    // return: const pointer to private key
    const PrivateKey* getPrivateKey() const;

    //-----------------------------------------------------
    // Encrypts a string
    //
    // str: string to be encrypted
    //
    // return: CryptoString; Structure which contains
    //         encrypted message
    //
    CryptoString encrypt(string str);

    //-----------------------------------------------------
    // Decrypts a string
    //
    // str: string to decrypt
    //
    // return: string; Decrypted message
    //
    string decrypt(CryptoString str);

    //-----------------------------------------------------
    // Encrypts a string
    //
    // ch: character to be encrypted
    //
    // return: CryptoChar; Boost's 256bit integer which contains
    //         the encrypted character
    //
    CryptoChar encrypt(char ch);

    //-----------------------------------------------------
    // Decrypts a string
    //
    // str: character to decrypt;  Boost's 256bit integer which contains
    //      the decrypted character
    //
    // return: char; Encrypted character
    //
    char decrypt(CryptoChar str);

    //-----------------------------------------------------
    // "<<" operator overload for printing key members to std::out
    friend std::ostream& operator <<(std::ostream& os, const RSA& rsa)
    {
      if ((rsa.public_key == nullptr) || (rsa.private_key == nullptr))
      {
        std::cout << "[ERROR] Can't print keys because one or both are null-pointers!\n";
      }
      std::cout << "---- PUBLIC KEY ----\n";
      std::cout << "---- r = " << rsa.getPublicKey()->r << " ----\n";
      std::cout << "---- m = " << rsa.getPublicKey()->m << " ----\n";
      std::cout << "---- PRIVATE KEY ----\n";
      std::cout << "---- s = " << rsa.getPrivateKey()->s << " ----\n";
      std::cout << "---- p = " << rsa.getPrivateKey()->p << " ----\n";
      std::cout << "---- q = " << rsa.getPrivateKey()->q << " ----\n";

      return os;
    }
  };
}

#endif