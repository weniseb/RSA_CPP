#include <string>
#include "Decryptor.h"
#include "RSA.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace Crypto;
using std::string;

Decryptor::Decryptor(const PrivateKey *key) : text(""), private_key(key)
{
};


string Decryptor::decryptString(CryptoString input)
{
  string cypher;

  int256_t tmp;
  int it;
  for (it = 0; it < input.size(); it++)
  {
    tmp = powm(input[it], private_key->s, private_key->q * private_key->p);
    cypher.push_back(tmp.convert_to<char>());
  }

  return cypher;
}

char Decryptor::decryptChar(CryptoChar c) const
{
  CryptoChar res = powm(c, private_key->s, private_key->q * private_key->p);
  return res.convert_to<int>();
}