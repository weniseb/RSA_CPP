//---------------------------------------------------------
// Implementaton of the chinese remainder theorem.
// Includes the basic and extended algorithm of the theorem.
//
// Author: Sebastian Weninger
//

#ifndef CHIN_REMAINDER
#define CHIN_REMAINDER

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

class ChinRemainder
{
private:

  int x1;
  int x2;

  int m1;
  int m2;

public:
  
  //-------------------------------------------------------
  // Constructor
  //
  ChinRemainder(int x1, int x2, int m1, int m2);

  //-------------------------------------------------------
  // Query if all parameters are set.
  //
  // return: bool
  //
  bool parametersSet();

  //-------------------------------------------------------
  // Calculate result with initialized modules
  // 
  // return: int265_t result
  //
  int256_t calculate();
};

#endif