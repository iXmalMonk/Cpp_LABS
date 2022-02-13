#include<iostream>

int main()
{
	system("chcp 1251");
	system("cls");

	int a, b;

	printf("A = ");
	scanf_s("%i", &a);

	do {
		printf("B = ");
		scanf_s("%i", &b);
	} while (b <= a || b == 0);

	printf("\n");


	for (int i = a; i <= b; i++)
	{
		for (int x = a; x <= b; x++)
		{
			for (int y = a; y <= b; y++)
				if ((2 * x + 3 * y) == i) printf("X = %i\nY = %i\nZ = %i\n---------- %i + %i = %i\n", x, y, i, 2 * x, 3 * y, i);
		}
	}
}

// Найти все целочисленные решения уравнения 2x+3y=z на интервале от А до В.