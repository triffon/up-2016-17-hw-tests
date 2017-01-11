#include <iostream>

using namespace std;

// a helper function that removes the digit shifted at power10
unsigned removeDigit(unsigned a, unsigned long long power10)
{
    unsigned long long nextPower = power10*10;

    //the digits, right from the one removed
    unsigned remainder = a % power10;
    //calculate the new number:
    //  remove the pointed digit and all right of it -> (a / nextPower)
    //  shift the result back (with one digit less -> * power10
    //  and add the remaining digits -> + remainder
    unsigned newNumber = (a / nextPower) * power10 + remainder;
    return newNumber;
}

// check if two given numbers are similar - b is a with one digit removed
bool isSimilarNumbers(unsigned a, unsigned b)
{
    // marker which digit will try to remove
    // note the type!
    unsigned long long power10 = 1;

    // while there are digits to remove
    while (power10 <= a)
    {
        // if removing current digit we get the second number
        // we are done
        if (removeDigit(a, power10) == b)
            return true;
        // go to the next number
        power10 *= 10;
    }
    return false;
}

int main()
{
    unsigned a, b;
    cin >> a >> b;

    if (isSimilarNumbers(a, b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
