#include <iostream>
#include <cmath>
using namespace std;

int main() {

  /*
    Let's assume the coefficients are named as follows:

    | a11 * x + a12 * y == b1
    | a21 * x + a22 * y == b2

  */

  // input coefficients are with five decimal digits, so "double" should be enough
  // assuming there are no extremely large or small exponents
  double a11, a12, a21, a22, b1, b2;

  // for calculations we will use a precision of ten digits after the decimal point
  // (in fact the tests we checked with even EPS = 0.1 would have been enough)
  double const EPS = 1e-10;

  // read all coefficients
  cin >> a11 >> a12 >> b1;
  cin >> a21 >> a22 >> b2;

  // please note that direct comparison with zero for the coefficients is OK
  // because we compare the inputs directly, without having performed any calculations with them

  // let's clear out some edge cases first
  if (a11 == 0 && a21 == 0) {
    // both coefficients for x are zero, so x does not influence the system of equations

    // we effectively obtain two linear equations for y:
    // | a12 * y == b1
    // | a22 * y == b2

    // if three is no solution for y, then there are no solutions to the system of equations
    // there are two cases
    if (
    // 1. one of the equations has no solutions
        a12 == 0 && b1 != 0 || a22 == 0 && b2 != 0
    // 2. both equations for y have exactly one solution, but they are different
    // i.e., b1 / a12 != b2 / a22
    // but we need to check with a precision EPS, since division results in loss of precision
        || a12 != 0 && a22 != 0 && fabs(b1 / a12 - b2 / a22) >= EPS)
      cout << "No solution\n";
    else
      // in all other cases (both equations have infinitely many soltuions,
      // or one of them has infinitely many solutions and the other has exactly one solution)
      // we are sure that there is at least one solution for y
      // therefore, we have many solutions for the whole system
      cout << "Many solutions\n";

  } else {
    // OK, now we know that there is at least one nonzero coefficient for x
    // to make things definite (and avoid duplicate cases) let's make sure that a11 != 0

    if (a11 == 0) {
      // if it is not, just swap the two equations
        double tmp = a11;
        a11 = a21;
        a21 = tmp;

        tmp = a12;
        a12 = a22;
        a22 = tmp;

        tmp = b1;
        b1 = b2;
        b2 = tmp;
      }

      // OK, now we know that a11 != 0
      // now let's make sure that a21 == 0 by cancelling it
      // this means multiplying the first equation by - a21 / a11 and adding it to the second one
      double coef = -a21 / a11;

      // we don't need to bother with setting a21 to zero, because we won't need it anymore
      // the other two coefficients are important:
      a22 += coef * a12;
      b2 += coef * b1;

      // OK, now we can solve the second equation for y, which becomes a22 * y == b2
      // there are three cases
      if (fabs(a22) < EPS)
        // the coefficient a22 for y turned out to be zero, let's check b2
        if (fabs(b2) < EPS)
          // 1. OK, so we have 0 * y = 0
          // therefore we have many solutoins for y
          // since a11 != 0, we have one solution for x for each solution for y
          // therefore, many solutions for the whole system
          cout << "Many solutions\n";
        else
          // 2. we have 0 * y = b2 != 0
          // therefore, no solutions for y, and no solutions for the entire system
          cout << "No solution\n";
      else {
        // 3. we have a non-zero coefficient for y
        // therefore, we have exactly one solution to the system of equations
        // let's solve it then :)
        double y = b2 / a22;
        double x = (b1 - a12 * y) / a11;

        // set to output with precision of 5 digits
        // for more information see http://www.cplusplus.com/reference/ios/ios_base/precision/
        cout.precision(5);

        // output the solutions
        cout << x << ' ' << y << endl;
      }
  }
  return 0;
}
