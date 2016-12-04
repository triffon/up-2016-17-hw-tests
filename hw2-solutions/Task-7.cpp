/*
 The core of the task is calculating large power quickly, but also manage to fit in 64 bit numbers.
 So we will work with modulo operation at each step of the calculation.
*/
#include <iostream>
using namespace std;

// Quick power method
// A power of the number can be easily calculated in the following way:
//  x^n =
//   1           , if n == 0
//   x           , if n == 1
//   x*(x^(n-1)) , if n is odd
//   (x^(n/2))^2 , if n is even
unsigned powerMod(unsigned x, unsigned n, unsigned mod)
{
    if (n == 0) return 1;
    if (n == 1) return x % mod;

    // in both other cases we will calculate power of n/2
    // longer number in needed to calculate the square, before apply modulo
    unsigned long long half = powerMod(x, n/2, mod);
    half = (half*half)%mod;

    if (n % 2 == 0)
        return half;
    else
        return (half*x)%mod;
}

int main()
{
    unsigned n, m, y;
    cin >> n >> m >> y;

    // mark when we found a valid value of X
    bool printed = false;

    // Using the fast power method it is easy just to iterate all the possible values of X
    for (unsigned x = 1; x < m; ++x)
    {
        if (powerMod(x, n, m) == y)
        {
            // here we put a space before the number
            // but only in the case it is not the first one
            cout << (printed?" ":"") << x;
            printed = true;
        }
    }

    //At the end handle the case where no X was found
    if (printed)
    {
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
