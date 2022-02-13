#include<iostream>

int main()
{
	system("chcp 1251");

	float a, b = 1;
	printf("Введите число А = ");
	scanf_s("%f", &a);

	while (a > sqrt(b))
	{
		printf("%f = %f\n", sqrt(b), b);
		b++;
	}
}

// Вывести все числа, меньшие заданного числа A, из последовательности sqrt(2), sqrt(3), sqrt(4) и т.д.