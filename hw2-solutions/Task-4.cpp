#include <iostream>
#include <cmath>
using namespace std;

unsigned int lastDigit(int n)
{
	return abs(n % 10);
}

int cutLastDigit(int n)
{
	return n / 10;
}

bool constainsDigit(int digit, int n)
{
	do
	{
		if(lastDigit(n) == digit)
			return true;
		n = cutLastDigit(n);
	}
	while (n != 0);
	return false;
}

bool digitSetsAreSame(int a, int b)
{
	for (int digit = 0; digit < 9; ++digit)
		if(constainsDigit(digit, a) != constainsDigit(digit, b))
			return false;
	return true;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << (digitSetsAreSame(a, b) ? "Yes" : "No") << endl;
	return 0;
}
