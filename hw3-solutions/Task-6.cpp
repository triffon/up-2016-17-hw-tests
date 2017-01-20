#include <iostream>

// Swap functions for each array:
void swapFns(unsigned& l, unsigned& r)
{
	unsigned temp = l;
	l = r;
	r = temp;
}

void swapTasks(short& l, short& r)
{
	short temp = l;
	l = r;
	r = temp;
}

void swapPoints(float& l, float& r)
{
	float temp = l;
	l = r;
	r = temp;
}

// Gives coefficent by which to compare each line
unsigned coeff(unsigned fn, short task)
{
	// Exapmles : 
	// 45123 3 0.5 => 4512303
	// 802341 10 2 => 80234110

	return fn*100 + task;
}

void print(unsigned *fns, short *tks, float *pts, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << fns[i] << " "
				  << tks[i] << " "
				  << pts[i] << std::endl;
	}
}

// Using simple selection sort, customized to work 
// with the three arrays as one
void sort(unsigned *fns, short *tks, float *pts, const int size)
{

	// When there is no or one line 
	// the arrays are sorted.
	if (size == 1 || size == 0)
		return;

	for (int i = 0; i < size - 1; i++)
	{
		int minIdx = i,
			idx    = i + 1;

		// Searching for the the index of the smallest element
		// in the array begining from 'idx'.
		// Using the 'coeff' function to compare lines.
		while(idx < size)
		{
			if (coeff(fns[idx], tks[idx]) < coeff(fns[minIdx], tks[minIdx]))
				minIdx = idx;
			idx++;
		}

		// Swapping the elements on the index of the smallest element
		// with the elements on the current index 'i'.
		swapFns(fns[minIdx], fns[i]);
		swapTasks(tks[minIdx], tks[i]);
		swapPoints(pts[minIdx], pts[i]);

		// Here the first 'i' elements are sorted.
	}
}

int main()
{
	int size;
	std::cin >> size;

	unsigned *fns = new unsigned [size];
	short 	 *tks = new short    [size];
	float    *pts = new float    [size];

	for (int i = 0; i < size; i++)
		std::cin >> fns[i] >> tks[i] >> pts[i];

	sort(fns, tks, pts, size);

	print(fns, tks, pts, size);

	delete[] fns;
	delete[] tks;
	delete[] pts;

	return 0;
}

