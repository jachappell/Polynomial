#include "Polynomial.h"

#include <iostream>

using namespace std;

int main()
{
  // Create a third degree polynomial: 2x^3 - 3x^2 + 4x + 1

  double c[4];

  c[0] = 1.0;
  c[1] = 4.0;
  c[2] = -3.0;
  c[3] = 2.0;

  Polynomial<double> poly(c, 3);

  // evaluate the polynomial for a range of values
  for (auto x = -10.0 ; x <= 10.0; x = x + 1.0)
  {
    cout << "poly(" << x << ") = " << poly(x) << endl;
  }

  return 0;
}
