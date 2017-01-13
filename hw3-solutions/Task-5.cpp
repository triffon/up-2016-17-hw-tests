#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

short findNextSpaceOrEnd(char* start)
{
	if (start[0] == ' ' || start[0] == '\0')
		return 0;
	else
		return 1 + findNextSpaceOrEnd(start + 1);
}

unsigned short decimalDigit(char digit)
{
	if (digit >= '0' && digit <= '9')
		return digit - '0';
	else if (digit >= 'A' && digit <= 'F')
		return digit - 'A' + 10;
	else if (digit >= 'a' && digit <= 'f')
		return digit - 'a' + 10;
}

unsigned long long parseToBase(char* number, int size, int base)
{
	if (size == 0)
	 	return 0;
	return (parseToBase(number, size - 1, base) * base) + decimalDigit(number[size - 1]);
}

int main()
{
	const unsigned int MAX_CHARACTERS = 1000;
	char expression[MAX_CHARACTERS];
	cin.getline(expression, MAX_CHARACTERS);
	int size = 0, step = 0;

	unsigned long long sum = 0;
	unsigned short expressionLength = strlen(expression);
	for (int i = 0; i < expressionLength; i += step)
	{
		step = 1;
		if (isDigit(expression[i]))
		{
			size = findNextSpaceOrEnd(expression + i);
			if (expression[i] == '0' && i < expressionLength - 1)
			{
				if (expression[i + 1] == 'b')
					sum += parseToBase(expression + i + 2, size - 2, 2);
				else if(expression[i + 1] == 'x')
					sum += parseToBase(expression + i + 2, size - 2, 16);
				else if (isDigit(expression[i + 1]))
					sum += parseToBase(expression + i + 1, size - 1, 8);
			}
			else
			{
				sum += parseToBase(expression + i, size, 10);
			}
			step = size;
		}

	}

	cout << sum << endl;

	return 0;
}
