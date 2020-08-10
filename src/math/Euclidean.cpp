#include "Euclidean.h"

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

Euclidean::Euclidean()
{};

Euclidean::~Euclidean()
{};

int256_t Euclidean::extendedEuclidean(int256_t a, int256_t b, int256_t* x, int256_t* s)
{
  if ((a == 0) || (b == 0))
  {
    return 0;
  }

  int256_t q = 0;
  int256_t r = 0;

  q = a / b;

  //remainder
  r = a % b;

  int256_t x_tmp = *x;
  int256_t s_tmp = *s;
  if (r != 0)
  {
    extendedEuclidean(b, r, &x_tmp, &s_tmp);
  }

  if (r == 0)
  {
    *x = 0;
    *s = 1;

    return b;
  }

  *x = s_tmp;
  *s = x_tmp - (q * s_tmp);

  return b;
}

int256_t Euclidean::euclidean(int256_t a, int256_t b)
{

  if ((a == 0) || (b == 0))
  {
    return 0;
  }

  int256_t q;
  int256_t r;

  do
  {
    q = a / b;
    r = a % b;

    a = b;
    b = r;
  } while (r != 0);

  return a;
}