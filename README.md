# RSA_CPP

## Project Description
This project contains the implementation of the popular RSA cryptosystem in **C++**.  
Currently the cryptosystem supports en-/decryption of a single character or a whole string.  
  
The **RSA key-length** is currently *256 bit*. The *boost multiprecision* subset is used for that key length implementation.  
(It is a dynamic *key-length* implementation planned)

## Project structure
The complete implementation and all source files are in the subdirectory **src/**.  
Src contains the *three* "main" classes, which are **RSA**, **Encryptor** and **Decryptor**.  
Also there are two additional subdirectories **math** and **tests**.  
Below is described what are the three modules and what is living in the **math** and **tests** subdirectories.

### The three "main" modules
#### RSA.h
This is the main class for the encryption and decryption process.
#### Encryptor.h
RSA uses this class to encrypt data.   
Encryptor does all neccessary calculation to encrypt the data.
#### Decryptor.h
RSA uses this class to decrypt data.  
Decryptor does all neccessary calculation to decrypt the data.  

### Math and tests subdirectories
#### Math
This directory contains all mathematical algorithms the *RSA* cryptosystem uses.  
Containing algorithms are the *basic euclidean algorithm* to calculate the *greatest common divisor* of two integers and the *extended euclidean algorithm* to calculate the *inverse representants* of the two input integers. One use case of the *extended euclidean algorithm* is to calculate one member of the secret key.
#### Tests
Contains *unit tests*.

## Usage
First of all an instance of RSA has to be created.  
RSA has two main functions *encrypt()* and *decrypt()*. Each two times, one for en-/decrypt strings and one for en-/decrypt characters.  
The method signatures are the following:  
```
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
// return: char; Decrypted character
//
char decrypt(CryptoChar str);
```
All together an example for an en-/decryption of a string:
```
try
{
  Crypto::RSA rsa(6907, 7687, 24);

  // Message to encrypt
  string in_str = "This is a bretty long message, with extra special caharacters and no deeber meaning!";

  // Encrypt message
  Crypto::CryptoString out_str = rsa.encrypt(in_str);
  // Decrypt message
  string res_str = rsa.decrypt(out_str);

  // Print to console
  std::cout << "input: " << in_str << " | output: " << res_str << "\n";
}
catch (std::exception &e)
{
  std::cout << e.what();
}
```

## License
MIT License

Copyright (c) 2020 Sebastian Weninger

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
