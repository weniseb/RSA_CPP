//---------------------------------------------------------
// Implementation of the basic and extended euclidean algorithm.
// Mainly used for secret key calculation.
// 
// Input and output of the algorithms are 256 bit integers from the
// boost library.
//
// Author: Sebastian Weninger
//

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

#ifndef EUCLIDEAN_
#define EUCLIDEAN_

class Euclidean
{
  private:
    // Constructor
    Euclidean();
    // Desctructor
    ~Euclidean();
  public:

    ///----------------------------------------------------
    // Extended euclidean algorithm to calculate gcd of
    // two integers and it's inverse representatives.
    //
    //
    // *x: pointer to inverse of a
    // *s: pointer to inverse of b (secret key in cryptography)
    //
    // return: gcd of a and b
    //
    static int256_t extendedEuclidean(int256_t a, int256_t b, int256_t* x, int256_t* s);

    //-----------------------------------------------------
    // Basic euclidean algorithm to calculate gcd of
    // two integers.
    //
    // return: gcd of a and b
    //
    static int256_t euclidean(int256_t a, int256_t b);
};

#endif

