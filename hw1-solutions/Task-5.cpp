//Homework 1 task 5 solution 
//author Ivan Filipov 

#include<iostream>
#include<cmath>

//given for the task
int const R1 = 8, R2 = 3, R3 = 1; //radiuses

int const PntAw1 = 10, PntAw2 = 20, PntAw3 = 60, Outside = 0; //points awards

//precision for compare operations
double const PRE = 0.001;

int main() {

	//inputs
	double ShotPntX, ShotPntY, LookPntX, LookPntY;

	std::cin >> ShotPntX >> ShotPntY >> LookPntX >> LookPntY;


	//calculating where the "new" center is
	double centerX, centerY;

	//the "tricky" moment 
	centerX = (-1.0) * LookPntX;
	centerY = (-1.0) * LookPntY;

	//the distance between the shot point and the darts' center
	double Dist = sqrt((centerX - ShotPntX) * (centerX - ShotPntX) +
		           (centerY - ShotPntY) * (centerY - ShotPntY));

	//too far away 
	if (Dist - R1 > PRE) {
		std::cout << Outside << '\n';
		return 0;  //stopping the program because we already know the answer 
	}

	//on boarder
	if ((abs(Dist - R1) < PRE ) ||
	    (abs(Dist - R2) < PRE ) ||
	    (abs(Dist - R3) < PRE )) {

		std::cout << Outside << '\n';
		return 0;
	}

	//checking in which circle the shot has fallen 
	//inside -> outside
	if (Dist - R3 < PRE)              //smallest
		std::cout << PntAw3;
	else if (Dist - R2 < PRE)        //medium
		std::cout << PntAw2;
	else if (Dist - R1 < PRE)         //the large one
		std::cout << PntAw1;

	std::cout << '\n';

	return 0;
}
