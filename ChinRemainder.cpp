#include "ChinRemainder.h"
#include "Euclidean.h"

ChinRemainder::ChinRemainder(int x1, int x2, int m1, int m2) : x1(x1), x2(x2), m1(m1), m2(m2)
{};

bool ChinRemainder::parametersSet()
{
  if (x1 == 0 || x2 == 0 || m1 == 0 || m2 == 0)
  {
    return false;
  }

  return true;
}

int256_t ChinRemainder::calculate()
{
  if (!parametersSet())
  {
    return 0;
  }

  int a = x1 * m2;
  int b = x2 * m1;

  int256_t x, s;

  Euclidean::extendedEuclidean(a, m2, &x, &s);
}