#include<iostream>
#include"Stack.h"

void pushStack(Stack* stack, int number)
{
	Element* tmp = (Element*)malloc(sizeof(Element));

	if (!tmp) return;

	tmp->next = stack->head;
	tmp->data = number;
	stack->head = tmp;
}

int popStack(Stack* stack)
{
	Element* tmp;
	int number = 0;
	if (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		number = tmp->data;
		free(tmp);
	}
	return number;
}

int peekStack(Stack* stack)
{
	if (stack->head == NULL) return 0;

	int number = stack->head->data;

	return number;
}

void printStack(Stack const* stack)
{
	for (Element* current = stack->head; current != NULL; current = current->next)
		printf("%i ", current->data);
}

void clearStack(Stack* stack)
{
	if (stack->head)
	{
		Element* tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}
}

bool checkIfStackIsEmpty(Stack* stack)
{
	if (stack->head != NULL) return true;
	return false;
}