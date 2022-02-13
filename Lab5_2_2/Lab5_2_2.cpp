#define _USE_MATH_DEFINES
#include<iostream>

int main()
{
	system("chcp 1251");

	int x;
	float f;

	printf("¬ведите x = ");
	scanf_s("%i", &x);

	if (x < 0) f = x * x * x;
	if (x >= 0 && x <= 10) f = 4 * cos(x * M_PI / 180);
	if (x > 10) f = tan(x * M_PI / 180);
	printf("F = %.3f", f);
}

// x^3 | x < 0
// 4*cos(x) | 0 <= x <= 10
// tg(x) | x > 10