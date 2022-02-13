#define _USE_MATH_DEFINES
#include<iostream>

// x^3 | x < 0
// 4*cos(x) | 0 <= x <= 10
// tg(x) | x > 10

int main()
{
	system("chcp 1251");

	double a, b, c;

	printf("¬ведите a = ");
	scanf_s("%lf", &a);

	do
	{
		printf("¬ведите b = ");
		scanf_s("%lf", &b);
	} while (b <= a);

	do
	{
		printf("¬ведите c = ");
		scanf_s("%lf", &c);
	} while (c <= 0);

	for (double i = a; i <= b; i += c)
	{
		double f;
		if (i < 0)
		{
			f = i * i * i;
			printf("i = %.3lf | X^3 = %.3lf\n", i, f);
		}
		else if (i <= 10)
		{
			f = 4 * cos(i * M_PI / 180);
			printf("i = %.3lf | 4 * Cos(X) = %.3lf\n", i, f);
		}
		else
		{
			f = tan(i * M_PI / 180);
			printf("i = %.3lf | Tan(X) = %.3lf\n", i, f);
		}
	}
}
