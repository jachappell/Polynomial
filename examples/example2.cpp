#include "Polynomial.h"

#include <iostream>

using namespace std;

int main()
{
  // Create a 4th degree polynomial: x^4 + 2x^3 - 3x^2 + 4x + 1

  double c[4];

  c[0] = 1.0;
  c[1] = 4.0;
  c[2] = -3.0;
  c[3] = 2.0;
  c[4] = 1.0;

  Polynomial<double> f(c, 4);

  // evaluate the polynomial and its derivative for a range of values
  for (double x = -10.0 ; x <= 10.0; x = x + 1.0)
  {
    double dy;
    double y = f(x, dy);
    cout << "f(" << x << ") = " << y << ", f'(" << x << ") = " << dy << endl;
  }

  return 0;
}
