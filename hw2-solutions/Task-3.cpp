#include <iostream>
#include <cmath>
using namespace std;

unsigned int lastDigit(unsigned int n)
{
	return abs(n % 10);
}

bool endsWith(unsigned int end, unsigned int n)
{
	if (end > n)
		return false;
	do
	{
		if(lastDigit(n) != lastDigit(end))
			return false;
		n /= 10;
		end /= 10;
	}
	while (end != 0);
	return true;
}

unsigned int countOccurunces(unsigned int needle, unsigned int haystack)
{
	unsigned int occurunces = 0;
	do
	{
		if(endsWith(needle, haystack))
			occurunces += 1;
		haystack /= 10;
	}
	while (haystack != 0);
	return occurunces;
}

int main()
{
	unsigned int a, b;
	cin >> a >> b;
	cout << countOccurunces(a, b) << endl;
	return 0;
}
