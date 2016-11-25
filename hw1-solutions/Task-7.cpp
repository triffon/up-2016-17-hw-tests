/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Svetomir Stoimenov
 * @task 7
 * @compiler GCC
 *
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, y;
	cin >> x >> y;

	// Разстоянието от въведената точка до центъра на координатната система
	double r = sqrt(x * x + y * y);
	// Разстоянието от въведената точка до центъра на малката черна окръжност
	double smallBlackCenterDistance = sqrt(x * x + (y - 3) * (y - 3));
	// Разстоянието от въведената точка до центъра на малката бяла окръжност
	double smallWhiteCenterDistance = sqrt(x * x + (y + 3) * (y + 3));

	/*За да преценим къде е точката, ще постъпим по следния начин:
		1. Ще проверим всички гранични случаи, а иммено
			1.1 Точката е извън фигурата (защото тогава я считаме за неутрална)
			1.2 Върху външната граница на фигурата
			1.3 Върху малката бяла окръжност
			1.4 Върху малката черна окръжност
			1.5 Върху дъгата между (0,0) и (0,-6), т.е. лявата половина на
				окръжността с център (0, -3) и радиус 3
			1.6 Върху дъгата между (0,0) и (0,6), т.е. дясната половина на
				окръжността с център (0, 3) и радиус 3
		Ако вече сме сигурни, че точката не е гранична:
		2. Проверяваме 2-те малки окръжности:
			2.1 В черната малка окръжност
			2.2 В бялата малка окръжност
		Ако вече сме сигурни, че точката не е гранична и не е в малките окръжности:
		3. Проверяваме 2-те полуокръжности
			3.1 В черната полуокръжност, т.е. лявата половина на
				окръжността с център (0, -3) и радиус 3
			3.2 В бялата полуокръжност, т.е. дясната половина на
				окръжността с център (0, 3) и радиус 3
		И последно, ако вече сме сигурни, че точката не е нито гранична,
		нито е в малките окръжности, нито в полуокръжностите:
		4.1 Ако е от ляво на ординатата, точката е "Добра"
		4.2 Ако е от дясно на ординатата, точката е "Зла"
	*/

	if(r > 6)
		cout << "Neutral" << endl;
	else if (r == 6)
		cout << "Neutral" << endl;
	else if (smallWhiteCenterDistance == 1)
		cout << "Neutral" << endl;
	else if (smallBlackCenterDistance == 1)
		cout << "Neutral" << endl;
	else if (smallWhiteCenterDistance == 3 && x <= 0)
		cout << "Neutral" << endl;
	else if (smallBlackCenterDistance == 3 && x >= 0)
		cout << "Neutral" << endl;
	else if (smallBlackCenterDistance < 1)
		cout << "Evil" << endl;
	else if (smallWhiteCenterDistance < 1)
		cout << "Good" << endl;
	else if (smallWhiteCenterDistance < 3 && x <= 0)
		cout << "Evil" << endl;
	else if (smallBlackCenterDistance < 3 && x >= 0)
		cout << "Good" << endl;
	else if (x < 0)
		cout << "Good" << endl;
	else
		cout << "Evil" << endl;

	return 0;
}
