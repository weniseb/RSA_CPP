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
    string in = "This is a bretty long message, with extra special caharacters and no deeber meaning!";

    Crypto::CryptoString out = rsa.encrypt(in);
    string res = rsa.decrypt(out);

    std::cout << "input: " << in << " | output: " << res << "\n";

  }
  catch (std::exception &e)
  {
    std::cout << e.what();
  }

  return 0;
}