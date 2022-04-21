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

	printf("%i\n", reverseNumber(&stack));

	deInitStack(&stack);

	return 0;
}

// Ввести некоторое число и записать его цифры в стек. Вывести
// число, у которого цифры идут в обратном порядке. Цифры из
// записи числа считывать поочередно (например, с помощью
// getch()). Вывести число, которое получится, если поменять цифры
// стоящие на четных и нечетных позициях местами.
