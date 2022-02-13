#include<iostream>

int main()
{
	system("chcp 1251");
	system("cls");

	int n, x, y = -1, z = 0;

	do {
		printf("i = ");
		scanf_s("%i", &n);
	} while (n <= 1);

	printf("X = ");
	scanf_s("%i", &x);

	for (int i = 1; i <= n; i++)
	{
		y *= -1;

		z += y * 3 * x;
	}

	printf("Ñóììà = %i\n", z);

	system("pause");
}

//	n
// E	(-1)^(i-1)*3*x
//	i=1