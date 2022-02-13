#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b;

	printf("X = ");
	scanf_s("%lf", &a);

	b = sqrt(1 - sin(a) * sin(a));

	printf("Ответ = %.3lf; X = %.3lf", b, a);
}

// sqrt(1 - sin(a) * sin(a))