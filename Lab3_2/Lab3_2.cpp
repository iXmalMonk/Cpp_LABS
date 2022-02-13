#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b, c;

	printf("”словие r < R\n„исло ѕи = 3.14\n");

	printf("¬нутренний радиус r (м) = ");
	scanf_s("%lf", &a);
	printf("¬нешний радиус R (м) = ");
	scanf_s("%lf", &b);

	if (b > a)
	{
		c = 3.14 * (b * b - a * a);

		printf("S кольца (м^2) = %.3lf; r = %.3lf, R = %.3lf\n", c, a, b);
	}
}

// ќпределить площадь кольца, внутренний радиус которого равен r, а внешний Ц заданному числу R (R > r).