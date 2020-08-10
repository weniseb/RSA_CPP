#include "RSA.h"
#include "math/Euclidean.h"
#include "Encryptor.h"
#include "Decryptor.h"
#include <exception>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace Crypto;

RSA::RSA(int256_t p, int256_t q, int256_t r) : p(0), q(0), m(0), phi_of_m(0), r(0), public_key(nullptr), private_key(nullptr)
{
  try
  {
    setParameters(p, q, r);
    calcKeys();
  }
  catch (std::exception &e)
  {
    //std::cout << e.what();
    throw; // Rethrow exception.
  }
}

void RSA::setParameters(int256_t p, int256_t q, int256_t r)
{
  this->p = p;
  this->q = q;
  this->r = r;
  this->m = p * q;
  this->phi_of_m = calcPhi(p, q);

  if (!isPrime(p) || !isPrime(q)) // p and q must be prime numbers
  {
    throw std::exception("[ERROR] p or q is not a prime number!");
  }
  else if ((r < m) && (r > 1) && (Euclidean::euclidean(r, phi_of_m) != 1)) // r and phi of m must be coprime
  {
    throw std::exception("[ERROR] r is not equal or less than p * q (=> m), or r and phi of m are not coprime!");
  }
}

void RSA::calcKeys()
{
  if (private_key != nullptr || public_key != nullptr)
  {
    throw std::exception("[ERROR] Keys already calculated!");
  }

  calcPublicKey();
  calcPrivateKey();
}

void RSA::calcPrivateKey()
{

  int256_t a = this->phi_of_m;
  int256_t b = this->r;

  int256_t s = 0;
  int256_t x = 0;

  //calculates the secret key
  Euclidean::extendedEuclidean(a, b, &x, &s);

  s = s < 0 ? makePositive(s, this->phi_of_m) : s;

  this->private_key = new PrivateKey{ s, this->p, this->q };
}

void RSA::calcPublicKey()
{
  this->public_key = new PublicKey{ this->r, this->m };
}

const PublicKey* RSA::getPublicKey() const
{
  return public_key;
}

const PrivateKey* RSA::getPrivateKey() const
{
  return private_key;
}

bool RSA::isPrime(int256_t numb)
{
  int it;
  for (it = 2; it < numb; it++)
  {
    if ((numb % it) == 0)
      return false;
  }

  return true;
}

int256_t RSA::calcPhi(int256_t a, int256_t b)
{
  if (!isPrime(a) || !isPrime(b))
  {
    return 0;
  }

  return (a - 1) * (b - 1);
}

int256_t RSA::makePositive(int256_t numb, int256_t mod) const
{
  int256_t tmp = numb;
  while (tmp < 0)
  {
    tmp += mod;
  }

  return tmp;
}

CryptoString RSA::encrypt(string str)
{
  Encryptor enc(public_key);
  CryptoString out = enc.encryptString(str);
  return out;
}

string RSA::decrypt(CryptoString str)
{
  Crypto::Decryptor dec(private_key);
  string res = dec.decryptString(str);
  return res;
}

CryptoChar RSA::encrypt(char ch)
{
  Encryptor enc(public_key);
  CryptoChar out = enc.encryptChar(ch);
  return out;
}

char RSA::decrypt(CryptoChar ch)
{
  Crypto::Decryptor dec(private_key);
  char res = dec.decryptChar(ch);
  return res;
}