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
    //-----------
    // String message
    //

    string in_str = "This is a bretty long message, with extra special caharacters and no deeber meaning!";

    Crypto::CryptoString out_str = rsa.encrypt(in_str);
    string res_str = rsa.decrypt(out_str);

    std::cout << "input: " << in_str << " | output: " << res_str << "\n";

    //-----------
    // Character message
    //

    char in_ch = 'X';

    Crypto::CryptoChar out_ch = rsa.encrypt(in_ch);
    char res_ch = rsa.decrypt(out_ch);

    std::cout << "input: " << in_ch << " | output: " << res_ch << "\n";

  }
  catch (std::exception &e)
  {
    std::cout << e.what();
  }

  return 0;
}