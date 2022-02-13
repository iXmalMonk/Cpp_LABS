#include<iostream>

int main()
{
	system("chcp 1251");
	system("cls");

	int minus = 1, i = 1, x;
	double accuracy, result = 0, s;

	do {
	printf("X = ");
	scanf_s("%i", &x);
	} while (x < -1);

	do {
		printf("Accuracy = ");
		scanf_s("%lf", &accuracy);
	} while (accuracy < 0);

	do {

		minus *= -1;

		double factorial = 1;
		for (int iter = 1; iter <= x + i; iter++)
		{
			factorial *= iter;
		}

		double i1 = i;
		for (int iter1 = 1; iter1 < i; iter1++)
		{
			i1 *= i;
		}

		s = minus * factorial / i1;

		result += s;

		i++;

	} while (fabs(s) > accuracy);

	printf("Result = %.3lf", result);

}

//	8
//E			(-1)^i * (x+i)! / i^i
//	i = 1
