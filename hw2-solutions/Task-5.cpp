#include <iostream>
using namespace std;

double max (double a, double b)
{
	return (a > b) ? a : b;
}

double coveredDistance(double initialSpeed, double acceleration, double timePeriod)
{
	return initialSpeed * timePeriod + 0.5 * acceleration * timePeriod * timePeriod;
}

double newSpeed(double initialSpeed, double acceleration, double timePeriod)
{
	return initialSpeed + acceleration * timePeriod;
}

int main()
{
	int n;
	double speed = 0, stepAcceleration = 0, distance = 0, stepDistance = 0, period = 0;
	cin >> n >> period;
	for (int step = 0; step < n; ++step)
	{
		cin >> stepAcceleration;
		stepDistance = coveredDistance(speed, stepAcceleration, period);
		// cut the distance to 0 if needed
		stepDistance = max(stepDistance, 0);
		distance += stepDistance;
		speed = newSpeed(speed, stepAcceleration, period);
		// cut the speed to 0 if needed
		speed = max(speed, 0);
	}
	cout.precision(5);
	cout << fixed << distance << endl;
	return 0;
}
