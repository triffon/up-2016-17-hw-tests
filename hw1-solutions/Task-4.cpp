/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Nikolay Babulkov
 * @task 4
 * @compiler GCC
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{	
	char figure, signFigX, signKingX;
	int figX, figY, kingX, kingY;
	bool rook, bishop, queen, knight, check;

	cin >> figure;
	cin >> signFigX >> figY;
	cin >> signKingX >> kingY;
	
	// Transforming the char values to integer coordinates
	figX = signFigX - 'a' + 1;
	kingX = signKingX - 'a' + 1;

	// Boolean expressions describing if a figure attacks the king
	rook = (figX == kingX) || (figY == kingY);
	bishop = (figX + figY == kingX + kingY) || (figX - figY == kingX - kingY);
	queen = rook || bishop;

	// The differences between the king and figure on both coordinates
	int diffX = abs(figX - kingX), 
		diffY = abs(figY - kingY);

	// The sum of coordinates is 3, excluding the cases in which 
	// the figures lie on the same row or column
	knight = (diffX + diffY) == 3 && diffX != 0 && diffY != 0;

	check = (figure == 'R' && rook) || (figure == 'B' && bishop) || 
		(figure == 'Q' && queen) || (figure == 'N' && knight);

	if (check)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
