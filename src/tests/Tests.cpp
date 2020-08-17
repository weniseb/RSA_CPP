#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include "../RSA.h"
#include "../Encryptor.h"
#include "../Decryptor.h"
#include "../math/Euclidean.h"

using namespace boost::multiprecision;

BOOST_AUTO_TEST_CASE(EuclideanTestsBasic)
{
  int256_t a1 = 702;
  int256_t b1 = 23;
  int256_t exp1 = 1;

  int256_t a2 = 61;
  int256_t b2 = 91273;
  int256_t exp2 = 1;

  int256_t a3 = 1;
  int256_t b3 = 0;
  int256_t exp3 = 0;

  int256_t res1_1 = Euclidean::euclidean(a1, b1);
  int256_t res1_2 = Euclidean::euclidean(b1, a1);
  int256_t res2_1 = Euclidean::euclidean(a2, b2);
  int256_t res2_2 = Euclidean::euclidean(b2, a2);
  int256_t res3_1 = Euclidean::euclidean(a3, b3);
  int256_t res3_2 = Euclidean::euclidean(b3, a3);

  BOOST_CHECK_EQUAL(exp1, res1_1);
  BOOST_CHECK_EQUAL(exp1, res1_2);
  BOOST_CHECK_EQUAL(exp2, res2_1);
  BOOST_CHECK_EQUAL(exp2, res2_2);
  BOOST_CHECK_EQUAL(exp3, res3_1);
  BOOST_CHECK_EQUAL(exp3, res3_2);
}

BOOST_AUTO_TEST_CASE(EuclideanTestsExtended)
{
  int256_t a1_1 = 702;
  int256_t b1_1 = 23;
  int256_t x1_1 = 0;
  int256_t s1_1 = 0;
  int256_t exp1_1 = -61;

  int256_t res1_1 = Euclidean::extendedEuclidean(a1_1, b1_1, &x1_1, &s1_1);
  BOOST_CHECK_EQUAL(exp1_1, (int256_t)s1_1);

  // ----------------------

  int256_t a1_2 = 23;
  int256_t b1_2 = 702;
  int256_t x1_2 = 0;
  int256_t s1_2 = 0;
  int256_t exp1_2 = 2;

  int256_t res1_2 = Euclidean::extendedEuclidean(a1_2, b1_2, &x1_2, &s1_2);
  BOOST_CHECK_EQUAL(exp1_2, (int256_t)s1_2);

  // ----------------------

  int256_t a2_1 = 61;
  int256_t b2_1 = 91273;
  int256_t x2_1 = 0;
  int256_t s2_1 = 0;
  int256_t exp2_1 = 18;

  int256_t res2_1 = Euclidean::extendedEuclidean(a2_1, b2_1, &x2_1, &s2_1);
  BOOST_CHECK_EQUAL(exp2_1, (int256_t)s2_1);

  // ----------------------

  int256_t a2_2 = 91273;
  int256_t b2_2 = 61;
  int256_t x2_2 = 0;
  int256_t s2_2 = 0;
  int256_t exp2_2 = -26933;

  int256_t res2_2 = Euclidean::extendedEuclidean(a2_2, b2_2, &x2_2, &s2_2);
  BOOST_CHECK_EQUAL(exp2_2, (int256_t)s2_2);

  // ----------------------

  int256_t a3 = 1;
  int256_t b3 = 0;
  int256_t x3 = 0;
  int256_t s3 = 0;
  int256_t exp3 = 0;

  x3 = 0;
  s3 = 0;
  int256_t res3 = Euclidean::extendedEuclidean(a3, b3, &x3, &s3);
  BOOST_CHECK_EQUAL(exp3, (int256_t)s3);
}