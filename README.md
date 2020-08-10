# RSA_CPP

## Project Description
This project contains the implementation of the popular RSA cryptosystem in **C++**.  
Currently the cryptosystem supports en-/decryption of a single character or a whole string.  
  
The **RSA key-length** is currently *256 bit*. The *boost multiprecision* subset is used for that key length implementation.  
(It is planed to implent a dynamic *key-length* implementation)

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
