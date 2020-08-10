#include <iostream>
#include <exception>
#include "src/RSA.h"
#include "src/Decryptor.h"
#include "src/Encryptor.h"

using std::string;

int main()
{
  Crypto::RSA rsa(6907, 7687, 491);
  
  try
  {
    const Crypto::PublicKey* pubKey = rsa.getPublicKey();
    const Crypto::PrivateKey* privKey = rsa.getPrivateKey();

    string in = "This is a bretty long message, with extra special caharacters and no deeber meaning!";

    Crypto::Encryptor enc(pubKey);
    Crypto::CryptoString out = enc.encryptString(in);

    Crypto::Decryptor dec(privKey);
    string res = dec.decryptString(out);

    std::cout << "input: " << in << " | output: " << res << "\n";

  }
  catch (std::exception &e)
  {
    std::cout << e.what();
  }

  return 0;
}