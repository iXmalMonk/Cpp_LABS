#include<iostream>
#include"Stack.h"

int numberLength(int number)
{
	int length = 0;

	while (number != 0)
	{
		length++;
		number /= 10;
	}

	return length;
}

int reverseNumber(Stack* stack)
{
	int number = 0;

	for (int i = 0, j = 1; i < stack->length; i++, j *= 10)
		number += popStack(stack) * j;

	return number;
}
	
int swapNumber(Stack* stack)
{
	//int j = 1, number = 0;

	//int* tmp = (int*)malloc(sizeof(int) * stack->length);

	//for (int i = 0; i < stack->length; i++)
	//	tmp[i] = popStack(stack);

	//for (int i = 1; i < stack->length; i++) j *= 10;

	//for (int i = 0; i < stack->length; i++)
	//	if (i % 2 == 0) number += tmp[i] * (j / 10);
	//	else
	//	{
	//		number += tmp[i] * j;
	//		j /= 100;
	//	}

	//if (stack->length % 2 != 0) number += tmp[stack->length - 1];

	//free(tmp);

	//return number;

	int j = 1, number = 0;

	for (int i = 1; i < stack->length; i++) j *= 10;

	for (int i = 0; i < stack->length; i++)
		if (i % 2 == 0) number += popStack(stack) * (j / 10);
		else
		{
			number += popStack(stack) * j;
			j /= 100;
			if (j == 1) j = 10;
		}

	return number;
}

int main()
{
	system("chcp 1251");
	system("cls");

	Stack stack;
	int number = 0;

	do {
		printf("Введите минимум 2х значное число: ");
		scanf_s("%i", &number);
	} while (number < 10);

	initStack(&stack, numberLength(number));

	while (number != 0)
	{
		pushStack(&stack, number % 10);
		number /= 10;
	}

	printStack(&stack);

	//printf("%i\n", reverseNumber(&stack));

	printf("%i\n", swapNumber(&stack));

	deInitStack(&stack);

	return 0;
}

// Ввести некоторое число и записать его цифры в стек. Вывести
// число, у которого цифры идут в обратном порядке. Цифры из
// записи числа считывать поочередно (например, с помощью
// getch()). Вывести число, которое получится, если поменять цифры
// стоящие на четных и нечетных позициях местами.