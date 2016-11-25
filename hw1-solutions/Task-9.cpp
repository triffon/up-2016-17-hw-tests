/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Svetomir Stoimenov
 * @task 9
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;

int main()
{
	const unsigned int BITS = 4;
	unsigned int firstOperand = 0, secondOperand = 0, result = 0;
	char operation;
	cin >> firstOperand >> operation >> secondOperand;
	/* Симулираме препълването като взимаме остатъкът при деление на 16
		* 16, защото калкулаторът е 4 битов, т.е. имаме 2^4 числа без знак
	*/
	firstOperand %= (1 << BITS);
	secondOperand %= (1 << BITS);

	/* Първо се "отърваваме" от делението на нула, като записваме в резултата -1,
		което ще е сигнал, именно за това.
		След като сме сигурни, че не делим на нула, извършваме съответната операция
	*/
	if(secondOperand == 0 && (operation == '/' || operation == '%'))
		result = -1;
	else if (operation == '+')
		result = firstOperand + secondOperand;
	else if (operation == '-')
		result = firstOperand - secondOperand;
	else if (operation == '*')
		result = firstOperand * secondOperand;
	else if (operation == '/')
		result = firstOperand / secondOperand;
	else if (operation == '%')
		result = firstOperand % secondOperand;

	if(result == -1)
		cout << "Division by zero!" << endl;
	else
		// Преди да изведем резултата, отново симулираме препълването
		cout << (result % (1 << BITS)) << endl;
	return 0;
}
