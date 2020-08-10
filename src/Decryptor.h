//---------------------------------------------------------
// Class to decrypt data.
//
// Author: Sebastian Weninger
//

#ifndef DECRYPTOR_
#define DECRYPTOR_

#include "RSA.h"
#include <string>

using std::string;

namespace Crypto
{
  class Decryptor
  {
  private:
    const PrivateKey* private_key;

    string text;

  public:
    // ------------------------------------------------------
    // Constructor
    Decryptor(const PrivateKey* key);

    // ------------------------------------------------------
    // Decrypts a whole string.
    //
    // input: input string
    // return: cypher string
    string decryptString(CryptoString input);

    //-------------------------------------------------------
    // Decrypts a single char.
    //
    // c: input char
    // return: decrypted char, represented as integer
    char decryptChar(CryptoChar c) const;
  };
}
#endif