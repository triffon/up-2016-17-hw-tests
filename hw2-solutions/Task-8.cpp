#include <iostream>
using namespace std;

int lastDigit(unsigned long long n)
{
	return n % 10;
}

unsigned long long cutLastDigit(unsigned long long n)
{
	return n / 10;
}

unsigned long long toBaseTen(int currentBase, unsigned long long n)
{
	int nInBaseTen = 0, multiplier = 1;
	do
	{
		nInBaseTen += lastDigit(n) * multiplier;
		n = cutLastDigit(n);
		multiplier *= currentBase;
	}
	while (n > 0);
	return nInBaseTen;
}

void printInBase(int k, unsigned long long n)
{
	if(n >= k)
		printInBase(k, n / k);
	cout << n % k;
}

bool isValidNumber(int base, unsigned long long n)
{
	do
	{
		if(lastDigit(n) >= base)
			return false;
		n = cutLastDigit(n);
	}
	while (n > 0);
	return true;
}

int main()
{
	unsigned long long n, m, k;
	cin >> n >> m >> k;
	if(isValidNumber(k, n) && isValidNumber(k, m))
		printInBase(k, toBaseTen(k, n) + toBaseTen(k, m));
	else
		cout << "Bad input data!";
	cout << endl;

	return 0;
}
