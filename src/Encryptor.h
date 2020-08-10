//---------------------------------------------------------
// Class to encrypt data.
//
// Author: Sebastian Weninger
//

#ifndef ENCRYPTOR_
#define ENCRYPTOR_

#include "RSA.h"
#include <string>

using std::string;

namespace Crypto
{
  class Encryptor
  {
  private:
    const PublicKey* public_key;

    string text;

  public:
    // ---------------------
    // Constructor
    //
    Encryptor(const PublicKey* key);

    // ---------------------
    // input: input string
    // return: Crypto string
    CryptoString encryptString(string& input);
    CryptoChar encryptChar(char c) const;
  };
}
#endif