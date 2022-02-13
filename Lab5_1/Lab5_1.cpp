#include<iostream>

int main()
{
	system("chcp 1251");

	float a, b;

	printf("Введите целое число = ");
	scanf_s("%f", &a);

	if (a > 0)
		b = sqrt(a);
	else
		b = a * 3;
	printf("Ответ = %.3f", b);
}

// Дано целое число. Если оно положительное, извлечь из него корень, в противном случае умножить на 3.