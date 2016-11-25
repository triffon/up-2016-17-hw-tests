/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Svetomir Stoimenov
 * @task 6
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;

int main()
{
	int x1, y1, h1, w1;
	int x2, y2, h2, w2;
	cin >> x1 >> y1 >> h1 >> w1;
	cin >> x2 >> y2 >> h2 >> w2;

	/*За да имат сечение двата правоъгълника, те трябва да се засичат както
		хоризонтално така и вертикално.*/
	int width, height, maxLeft, minRight, maxBottom, minTop;

	/*Aко двата правоъгълника се засичат хоризонтално, широчината на евентуалното
		им сечение можем да получим като от обсцисата на
		по-левия измежду десните им краища, извадим абсцисата на
		по-десния измежду левите им краища. :)
		Ако полученото число не е положително, то тогава нямаме хоризонтално засичане
	*/
	maxLeft = (x1 < x2) ? x2 : x1;
	minRight = (x1 + w1 < x2 + w2) ? x1 + w1 : x2 + w2;
	width = minRight - maxLeft;

	/*Аналогично на широчината, можем да пресметнем и височината на евентуалното
		сечеине:
		От ординатата на по-ниския измежду високите им краища, изваждаме
		ординатата по-високия измежду ниските им краища.
		Ако полученото число не е положително, то тогава нямаме вертикално засичане
	*/
	maxBottom = (y1 < y2) ? y2 : y1;
	minTop = (y1 + h1 < y2 + h2) ? y1 + h1 : y2 + h2;
	height = minTop - maxBottom;

	/* Ако нямаме хоризонтално или вертикално засичане, лицето е 0,
		в противен случай го пресмятаме
	*/
	cout << ((width <= 0 || height <= 0) ? 0 : width * height) << endl;

	return 0;
}
