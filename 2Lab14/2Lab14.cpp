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

void pushNumberInStack(Stack* stack, int number)
{
	int j = 1, number_length = numberLength(number);

	for (int i = 1; i < number_length; i++) j *= 10;

	while (number != 0)
	{
		pushStack(stack, number / j);
		number %= j;
		j /= 10;
		printStack(stack);
		printf("\n");
	}
}

int reverseNumber(Stack* stack)
{
	int length = 0, number = 0, j = 1;

	for (Element* current = stack->head; current != NULL; current = current->next)
	{
		length++;
		j *= 10;
	}
	
	j /= 10;

	for (int i = 0; i < length; i++)
	{
		number += popStack(stack) * j;
		j /= 10;
	}

	return number;
}

int swapNumber(Stack* stack)
{
	int j = 1, number = 0, length = 0;

	for (Element* current = stack->head; current != NULL; current = current->next)
	{
		length++;
		j *= 10;
	}

	j /= 10;

	int* tmp = (int*)malloc(sizeof(int) * length);

	for (int i = length - 1; i >= 0; i--)
		tmp[i] = popStack(stack);

	for (int i = 0; i < length; i++)
		if (i % 2 == 0) number += tmp[i] * (j / 10);
		else
		{
			number += tmp[i] * j;
			j /= 100;
		}

	if (length % 2 != 0) number += tmp[length - 1];

	free(tmp);

	return number;
}

int main()
{
	system("chcp 1251");
	system("cls");

	Stack stack;
	int number = 0;

	do {
		printf("¬ведите минимум 2х значное число: ");
		scanf_s("%i", &number);
	} while (number < 10);

	pushNumberInStack(&stack, number);

	//printf("\n%i", reverseNumber(&stack));
	printf("\n%i", swapNumber(&stack));

	clearStack(&stack);

	return 0;
}