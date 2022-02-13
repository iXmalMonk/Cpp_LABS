#define _USE_MATH_DEFINES
#include<iostream>

int main()
{
	system("chcp 1251");

	int a;
	float c, x;
	printf("1.Arcsin\n2.Arctan\n3.Ln\n4.^3\nВыберете пункт = ");
	scanf_s("%i", &a);

	switch (a)
	{
	case 1:
		printf("-1 <= x <= 1\nВведите x = ");
		scanf_s("%f", &x);
		if (x >= -1 && x <= 1)
		{
			c = asin(x);
			printf("Arcsin(x) = %.3f", c);
		}
		else
			printf("Неверный ввод!");
		break;
	case 2:
		printf("Введите x = ");
		scanf_s("%f", &x);
		c = atan(x);
		printf("Arctan(x) = %.3f", c);
		break;
	case 3:
		printf("0 < x\nВведите x = ");
		scanf_s("%f", &x);
		if (x > 0)
		{
			c = log(x);
			printf("Ln(x) = %.3f", c);
		}
		else
			printf("Неверный ввод!");
		break;
	case 4:
		printf("Введите x = ");
		scanf_s("%f", &x);
		c = x * x * x;
		printf("^3(x) = %.3f", c);
		break;

	default:
		printf("Неверный ввод!");
	}
}

// Определить арксинус, арктангенс, натуральный логарифм или куб введённого числа (на выбор пользователя).