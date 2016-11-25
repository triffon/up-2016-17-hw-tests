/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Svetomir Stoimenov
 * @task 8
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;

int main()
{
	unsigned int ammount = 0;
	cin >> ammount;
	cout << ammount << " = ";
	/* Флагът first, ще използваме, за да знаем при пресмятането на броя на
		банкнотите от даден номинал, дали вече имаме отпечатани стойности.
		Ако такива има - трябва да отпечатаме " + ", за да е коректен изхода.
	*/
	bool first = true;
	/* Ако сумата е по-голяма от съответния номинал (в случая 50),
		изчисляваме възможно най-големия брой банкноти от него,
		които можем да вземем за да я образуваме и го отпечатваме на екрана.
	*/
	if(ammount / 50 != 0)
	{
		cout << ammount / 50 << "*50";
		first = false;
	}
	/* Намаляваме сумата, защото вече сме взели съответния брой банкноти от номиналът*/
	ammount %= 50;
	// Повтаряме стъпките за всички номинални банкноти
	if(ammount / 20 != 0)
	{
		if(!first)
			cout << " + ";
		cout << ammount / 20 << "*20";
		first = false;
	}
	ammount %= 20;
	if(ammount / 10 != 0)
	{
		if(!first)
			cout << " + ";
		cout << ammount / 10 << "*10";
		first = false;
	}
	ammount %= 10;
	if(ammount / 5 != 0)
	{
		if(!first)
			cout << " + ";
		cout << ammount / 5 << "*5";
		first = false;
	}
	ammount %= 5;
	if(ammount / 2 != 0)
	{
		if(!first)
			cout << " + ";
		cout << ammount / 2 << "*2";
		first = false;
	}
	ammount %= 2;
	if(ammount != 0)
	{
		if(!first)
			cout << " + ";
		cout << ammount << "*1";
	}
	cout << endl;
	return 0;
}
