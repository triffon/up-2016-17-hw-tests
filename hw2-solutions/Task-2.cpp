#include <iostream>

using namespace std;


// Checks if a number is prime
bool isPrime(unsigned x)
{
    // 2 is prime and is the only even prime number
    if (x == 2) return true;
    // so 0, 1 ans all other even numbers are not prime
    if (x < 3 || x % 2 == 0) return false;

    // now we search for divisors between 3 and sqrt(x)
    // because x is odd, there is no point in test even divisors
    // so we try only odd ones -> the increasing step is 2
    for (unsigned div = 3; div*div <= x; div += 2)
    {
        if (x % div == 0)
        {
            // if div is divisor the number is not prime
            return false;
        }
    }

    // after finishing the search without success
    // we know the umber is prime
    return true;
}

// Checks if the number a is the smaller one from tween-prime pair
bool isTwinPrime(unsigned a)
{
    return isPrime(a) && isPrime(a+2);
}

int main()
{
    unsigned n;
    cin >> n;

    // how many twin pairs was printed
    unsigned count = 0;

    // the number that will be checked
    // we know, that 3 is the first candidate, so we start with it
    unsigned num = 3;

    while (count < n)
    {
        if (isTwinPrime(num))
        {
            cout << num << " "
                 << num + 2 << endl;
            ++count;
        }
        // no point to check even numbers -> the step will be 2
        num += 2;
    }

    return 0;
}
