#include <iostream>

using namespace std;

void printSum(int* currentNumbersInSum, int numberOfSummands)
{
    cout << currentNumbersInSum[0] << " = " << currentNumbersInSum[1];
    for (int ind = 2; ind < numberOfSummands; ++ind) cout << " + " << currentNumbersInSum[ind];
    cout << endl;
}

int minimal(int a, int b)
{
    if (a < b) return a;
    return b;
}

void printAllSums(int* currentNumbersInSum, int level, int currentSum, int number)
{
    if (level == 0)
    {
        currentNumbersInSum[0] = number; /// The first number in the array is the initial number so the rest of the sum can be
        printAllSums(currentNumbersInSum, level + 1, currentSum, number); /// generated from it (as a decreasing sequence).
        return;
    }
    if (currentSum == number)
    {
        printSum(currentNumbersInSum, level);
    }
    else
    {
        for (int summand = minimal(currentNumbersInSum[level - 1], number - currentSum); summand > 0; --summand)
        {
            currentNumbersInSum[level] = summand;
            printAllSums(currentNumbersInSum, level + 1, currentSum + summand, number);
        }
    }
}

int main()
{
    int currentNumbersInSum[33];
    int number;
    cin >> number;
	printAllSums(currentNumbersInSum, 0, 0, number);
	return 0;
}
