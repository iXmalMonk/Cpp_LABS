#include<iostream>

int main()
{
	system("chcp 1251");

	int a, b, counter = 0, result = 0;

	printf("Number = ");
	scanf_s("%i", &a);

	b = a;

	while (b > 0)
	{
		counter++;
		b /= 10;
	}

	if (counter % 2 == 1) a /= 10;

	while (a > 0)
	{
		if ((a % 10) % 2 == 0) result++;
		a /= 100;
	}

	printf("result = %i\ncounter = %i", result, counter);
}

// Дано целое положительное число. Определить количество четных цифр, стоящих на четной позиции.