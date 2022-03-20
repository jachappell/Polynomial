#include "Polynomial.h"

#include <iostream>

using namespace Storage_B::Polynomials;

int main()
{
  // Create a 4th degree polynomial: x^4 + 2x^3 - 3x^2 + 4x + 1

  double c[5];

  c[0] = 1.0;
  c[1] = 4.0;
  c[2] = -3.0;
  c[3] = 2.0;
  c[4] = 1.0;

  Polynomial<double> f(c, 4);

  // evaluate the polynomial and its derivative for a range of values
  for (auto x = -10.0 ; x <= 10.0; x = x + 1.0)
  {
    auto res = f.eval(x);
    std::cout << "f(" << x << ") = " << res.y
         << ", f'(" << x << ") = " << res.yp << '\n';
  }

  return 0;
}
