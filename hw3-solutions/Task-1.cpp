#include <iostream>
#include <fstream>

void printElement(int n)
{
	if(n == 1)
	{
		std::cout << 1;
		return;
	}

	printElement(n-1);
	std::cout << n;
	printElement(n-1);
}

int main()
{
	const int upper_limit = 19;
	const int lower_limit = 1;
	int n;
	std::cin >> n;
	if(n < lower_limit || n > upper_limit)
	{
		std::cout << "Bad input data" << std::endl;
		return 0;
	}

	printElement(n);
	std::cout << std::endl;
}