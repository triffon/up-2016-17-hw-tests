#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const unsigned int MAX_FIGURES = 16;
const int KING_MOVES[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1},
						{0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

const int KNIGHT_MOVES[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
						{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

unsigned int numberOfFigures;
char figureType[MAX_FIGURES];
char figureX[MAX_FIGURES];
unsigned figureY[MAX_FIGURES];

bool board[8][8];

bool isPosition(char x, unsigned y)
{
	return (x >= 'a' && x <= 'h') && (y >= 1 && y <= 8);
}

void markThreat(char x, unsigned y)
{
	board[8 - y][x - 'a'] = true;
}

bool isThreatened(char x, unsigned y)
{
	return board[8 - y][x - 'a'];
}

bool hasFigureOn(char x, unsigned y)
{
	for (int i = 0; i < numberOfFigures; ++i)
		if (figureX[i] == x && figureY[i] == y)
			return true;
	return false;
}

void staticThreat(const int displacements[][2], unsigned displacementsLength,
				char x, unsigned y)
{
	char threatX;
	int threatY;
	for (int i = 0; i < displacementsLength; ++i)
	{
		threatX = x + displacements[i][0];
		threatY = y + displacements[i][1];
		if (isPosition(threatX, threatY))
			markThreat(threatX, threatY);
	}
}

void movementThreat(char x, unsigned int y, int deltaX, int deltaY)
{
	char threatX = x + deltaX;
	int threatY = y + deltaY;
	bool blocked = false;
	while (isPosition(threatX, threatY) && !blocked)
	{
		markThreat(threatX, threatY);
		if (hasFigureOn(threatX, threatY))
			blocked = true;
		threatX += deltaX;
		threatY += deltaY;
	}
}

void kingThreat(char x, unsigned y)
{
	staticThreat(KING_MOVES, 8, x, y);
}

void knightThreat(char x, unsigned y)
{
	staticThreat(KNIGHT_MOVES, 8, x, y);
}

void bishopThreat(char x, unsigned y)
{
	movementThreat(x, y, 1, 1);
	movementThreat(x, y, 1, -1);
	movementThreat(x, y, -1, 1);
	movementThreat(x, y, -1, -1);
}

void rookThreat(char x, unsigned y)
{
	movementThreat(x, y, 1, 0);
	movementThreat(x, y, -1, 0);
	movementThreat(x, y, 0, 1);
	movementThreat(x, y, 0, -1);
}

void queenThreat(char x, unsigned y)
{
	bishopThreat(x, y);
	rookThreat(x, y);
}

void inputFigures()
{
	cin >> numberOfFigures;
	for (int i = 0; i < numberOfFigures; ++i)
	{
		cin >> figureType[i] >> figureX[i] >> figureY[i];
	}
}

void markFiguresThreats()
{
	for (int i = 0; i < numberOfFigures; ++i)
	{
		switch (figureType[i])
		{
			case 'Q': queenThreat(figureX[i], figureY[i]); break;
			case 'B': bishopThreat(figureX[i], figureY[i]); break;
			case 'N': knightThreat(figureX[i], figureY[i]); break;
			case 'R': rookThreat(figureX[i], figureY[i]); break;
			case 'K': kingThreat(figureX[i], figureY[i]); break;
		}
	}
}

bool kingCheck(char kingX, unsigned kingY)
{
	return isThreatened(kingX, kingY);
}

bool kingCantMove(char kingX, unsigned kingY)
{
	char kingMoveX;
	int kingMoveY;
	for (int i = 0; i < 8; ++i)
	{
		kingMoveX = kingX + KING_MOVES[i][0];
		kingMoveY = kingY + KING_MOVES[i][1];
		if (isPosition(kingMoveX, kingMoveY))
			if (!isThreatened(kingMoveX, kingMoveY))
				return false;
	}
	return true;

}

int main()
{
	inputFigures();
	char kingX;
	unsigned int kingY;
	cin >> kingX >> kingY;
	markFiguresThreats();

	bool check = kingCheck(kingX, kingY);
	bool cantMove = kingCantMove(kingX, kingY);

	if (check && cantMove)
		cout << "Checkmate!" << endl;
	else if (check)
		cout << "Check!" << endl;
	else if (cantMove)
		cout << "Stalemate!" << endl;
	else
		cout << "The show must go on!" << endl;

	return 0;
}
