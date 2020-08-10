# RSA_CPP

## Project Description
This project contains the implementation of the popular RSA cryptosystem in **C++**.  
Currently the cryptosystem supports en-/decryption of a single character or a whole string.  

## Project structure
The complete implementation and source files are in the subdirectory **src/**.  
Src contains the *three* main Classes, which are **RSA**, **Encryptor** and **Decryptro**.  
Also there are two additional subdirectories **math** and **tests**.  
Below is described what are the three modules and what is living in the **math** and **tests** subdirectories.

### The three main modules
#### RSA.h
This is the main class for the encryption and decryption.
#### Encryptor.h
RSA uses this class to encrypt data.   
Encryptor does all neccessary calculation to encrypt the data.
#### Decryptor.h
RSA uses this class to decrypt data.
Encryptor does all neccessary calculation to encrypt the data.  

### Math and tests subdirectories
#### Math
This directory contains all mathematical algorithms the *RSA* cryptosystem uses.
Containing algorithms are the *basic euclidean algorithm* to calculate the *greatest common divisor* of two integers and the *extended euclidean algorithm* to calculate the *inverse representants* of the two given integers. *The extended euclidean algorithm* will be used to calculate one member of the secret key.

## Usage
