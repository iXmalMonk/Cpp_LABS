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
		printf("������� ������� 2� ������� �����: ");
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

// ������ ��������� ����� � �������� ��� ����� � ����. �������
// �����, � �������� ����� ���� � �������� �������. ����� ��
// ������ ����� ��������� ���������� (��������, � �������
// getch()). ������� �����, ������� ���������, ���� �������� �����
// ������� �� ������ � �������� �������� �������.
