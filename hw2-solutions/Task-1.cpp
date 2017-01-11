//#include<stdio.h> for scanf and printf
#include<iostream>
#include<iomanip>
#include<cmath>

//read /write precisions 
const int InputDigits = 5;
const int OutputDigitsAfterComma = 3;

double const PI = 3.14;

// x1 == x2 <=> abs(x1 - x2) < 0.01
double const PRE = 0.01;

//rectangle coordinates using only two variables,
//because we know that the other coordinates are at -1*Rx and -1*Ry
double const Rx = 5.0, Ry = 2.0;

//checks if a point is in the rectangle or on it's borders
bool isInside(double x, double y) {

	//a point is inside or on border if it isn't outside
	return ((abs(x) - Rx > PRE) || (abs(y) - Ry > PRE)) ? false : true;
		
}

//calculates the distance between two points
double DistBetweenPnts(double x1, double y1, double x2, double y2) {

	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

}


//calculating the distance between an inside point
//and the intersection point of a line (made form the inside and the outside point) 
//and the given rectangle
double DistFromPntToRect(double InsideX, double InsideY,double OutX,double OutY) {

	double IntersectionX, IntersectionY;

	//ax + by + c = 0  line equation 
	double a, b, c;

	//some vectors math 
	a = InsideY - OutY;
	b = -(InsideX - OutX);

	c = -(a*InsideX + b*InsideY); //calculating "c" knowing the fact
	                              //that inside point is laying on the line

	//printf("%fx+%fy+%f = 0",a,b,c); //what the line equation looks like
	
	
	//trying each direction
	//in order to find where the intersection point is
	if (abs(OutY) - Ry > PRE) { 

		//trying up or down 
		(OutY > 0.0) ? IntersectionY = Ry : IntersectionY = -1.0 * Ry;

		//finding x using the leaner equation
		IntersectionX = (-1.0*(c + b*IntersectionY)) / a;

		//if the found point is in the rectangle 
		//we calculate the distance between the inside point and the intersection point
		if (isInside(IntersectionX, IntersectionY))
			return DistBetweenPnts(IntersectionX,IntersectionY,InsideX,InsideY);

	}

	if (abs(OutX) - Rx > PRE) {

		//trying left or right 
		(OutX > 0.0) ? IntersectionX = Rx : IntersectionX = -1.0 * Rx;

		//finding y using the leaner equation
		IntersectionY = (-1.0*(c + a*IntersectionX)) / b;

		//if the found point is in the rectangle 
		//we calculate the distance between the inside point and the intersection point
		if (isInside(IntersectionX, IntersectionY))
			return DistBetweenPnts(IntersectionX, IntersectionY, InsideX, InsideY);

	}

	//getting here only if we have a logic error
	return 0.0;

}

//calculates the "f" function form the task
double PathLen(double dist) {

	return  (((PI * dist / 2.0) + dist) / 2.0) ;

}




int main() {

	//how many points to read
	int N;
	//coordinates of the previous and current point
	double CurX, CurY, PrevX, PrevY;
	//booleans used in order not to call isInside function more than once
	bool wasLastInside, isCurInside;
	//all the distance traveled
	double PathSum = 0.0;

	/*
	//the "C" way a bit problem with reading "." as a digit 
	scanf("%d", &N);
	scanf("%6lf%6lf", &CurX, &CurY);
	*/

	std::cin >> N;
	std::cin >>std::setprecision(InputDigits)>> CurX >> CurY;
	
	isCurInside = isInside(CurX, CurY);

	while (--N) {

		wasLastInside = isCurInside;
		PrevX = CurX;
		PrevY = CurY;

		std::cin >> CurX >> CurY;
		isCurInside = isInside(CurX, CurY);

		if (wasLastInside && isCurInside) {

			//if the two points are inside we just add their distance to the sum
			PathSum += PathLen(DistBetweenPnts(CurX, CurY, PrevX, PrevY));
			continue; //moving to the next loop 
			          //because we have already done our job with these points

		}

		//skip if both points are outside
		if (!wasLastInside && !isCurInside)
			continue;
		
		if (!wasLastInside && isCurInside) {

			//if the current is inside and the previous was outside
			//we should add the distance from the current point 
			//to the interception point with the rectangle 
			PathSum += PathLen(DistFromPntToRect(CurX, CurY, PrevX, PrevY));
			continue;
		}

		if (wasLastInside && !isCurInside) {
            

			//if the current is outside and the previous was inside
			//we should add the distance from the previous point 
			//to the interception point with the rectangle 
			PathSum += PathLen(DistFromPntToRect(PrevX, PrevY, CurX, CurY));
			continue;

		}

	}

	std::cout << std::fixed << std::setprecision(OutputDigitsAfterComma) 
		      << PathSum << std::endl;

	//the "C" way 
	//printf("%.3f\n", PathSum);
		
	return 0;

}