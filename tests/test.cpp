#include "Polynomial.h"

#include <complex>
#include <iostream>

#define BOOST_TEST_MODULE Polynomial
#include <boost/test/included/unit_test.hpp>

using namespace std;
using namespace Storage_B::Polynomials;

// 0 degree polynomial
BOOST_AUTO_TEST_CASE(zero_degree)
{
  Polynomial<double> p0(42.0);

  BOOST_CHECK(p0.degree() == 0);
  BOOST_CHECK(p0[0] == 42.0);
  BOOST_CHECK(p0(0.123) == 42.0);
}

// first degree polynomial
BOOST_AUTO_TEST_CASE(first_degree)
{
  Polynomial<double> p1(0.0, 1);
  p1[0] = -1.0;
  p1[1] = 1.0;

  BOOST_CHECK(p1.degree() == 1);
  BOOST_CHECK(p1(0.0) == -1.0);
  BOOST_CHECK(p1(1.0) == 0.0);
  BOOST_CHECK(p1(2.0) == 1.0);
  BOOST_CHECK(p1(-1.0) == -2.0);
}

// second degree polynomial
BOOST_AUTO_TEST_CASE(second_degree)
{
  double c[3] ;

  c[0] = 2.0 ;
  c[1] = -1.0;
  c[2] = 3.0 ;

  Polynomial<double> p2(c, 2) ;
  
  BOOST_CHECK(p2.degree() == 2);
  BOOST_CHECK(p2(0.0) == 2.0);
  BOOST_CHECK(p2(1.0) == 4.0);
  BOOST_CHECK(p2(2.0) == 12.0);
}

// third degree polynomial
BOOST_AUTO_TEST_CASE(third_degree)
{
  vector<float> c;

  c.push_back(-1.0);
  c.push_back(1.0);
  c.push_back(-2.0);
  c.push_back(3.0);

  Polynomial<float> p3(c);
  
  BOOST_CHECK(p3.degree() == 3);
  BOOST_CHECK(p3(0.0) == -1.0);
  BOOST_CHECK(p3(1.0) == 1.0);
  BOOST_CHECK(p3(-1.0) == -7.0);
}

// increment degree
BOOST_AUTO_TEST_CASE(increment_degree)
{
  double c[3] ;

  c[0] = 2.0 ;
  c[1] = -1.0;
  c[2] = 3.0 ;

  Polynomial<double> p(c, 2) ;

  BOOST_CHECK(p.degree() == 2);

  p.IncrementDegree(12.0);

  BOOST_CHECK(p.degree() == 3);
  BOOST_CHECK(p[0] == 2);
  BOOST_CHECK(p[1] == -1.0);
  BOOST_CHECK(p[2] == 3.0);
  BOOST_CHECK(p[3] == 12.0);
}

// decrement degree
BOOST_AUTO_TEST_CASE(decrement_degree)
{
  double c[3] ;

  c[0] = 2.0 ;
  c[1] = -1.0;
  c[2] = 3.0 ;

  Polynomial<double> p(c, 2);

  BOOST_CHECK(p.degree() == 2);

  auto val = p.DecrementDegree();

  BOOST_CHECK(p.degree() == 1);
  BOOST_CHECK(p[0] == 2);
  BOOST_CHECK(p[1] == -1.0);
  BOOST_CHECK(val == 3.0);
}

// complex polynomial
BOOST_AUTO_TEST_CASE(complex_poly)
{
  Polynomial<complex<double> > p;
  p[0] = 1.0;
  p.IncrementDegree(0.0);
  p.IncrementDegree(1.0);

  BOOST_CHECK(p.degree() == 2);
  BOOST_CHECK(p(1.0i) == 0.0);
  
  p.IncrementDegree();

  BOOST_CHECK(p.degree() == 3);
  BOOST_CHECK(p[3] == 0.0);

  p[3] = 2.0 - 3.0i;
  complex<double> result = p(2.0 + 1.0i);

  BOOST_CHECK(result.real() == 41);
  BOOST_CHECK(result.imag() == 20);
}

// Evaluate
BOOST_AUTO_TEST_CASE(derivative)
{
  vector<double> c;

  c.push_back(2.0) ;
  c.push_back(-1.0);
  c.push_back(3.0) ;
  Polynomial<double> f(c);

  c.clear();
  c.push_back(f[1]);
  c.push_back(2.0 * f[2]);
  Polynomial<double> fprime(c);

  double x = 42.0;
 
  auto res = f.Eval(x);

  BOOST_CHECK(res.first == f(x)); // y = f(x) 
  BOOST_CHECK(res.second == fprime(x)); // dy/dx = f'(x)
}
