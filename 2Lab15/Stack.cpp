#include<iostream>
#include"Stack.h"

void insertStack(Stack* stack, int number, int position)
{
	Element* tmp = (Element*)malloc(sizeof(Element));

	if (!tmp) return;
	
	int counter = 0;

	for (Element* current = stack->head; current != NULL; current = current->next) counter++;

	if (position >= counter) pushStack(stack, number);
	else if (position == 0)
	{
		tmp->data = number;
		Element* old_head = stack->head; // old
		stack->head = tmp; // new
		tmp->next = old_head;
	}
	else
	{
		int i = 0;
		Element* next = stack->head, *prev = NULL;
		while (i != position)
		{
			prev = next;
			next = next->next;
			i++;
		}
		tmp->data = number;
		tmp->next = next;
		prev->next = tmp;
	}
}

void pushStack(Stack* stack, int number)
{
	Element* tmp = (Element*)malloc(sizeof(Element));

	if (!tmp) return;

	tmp->data = number;
	tmp->next = NULL;

	if (stack->head == NULL)
	{
		stack->head = tmp;
		stack->tail = tmp;
	}
	else
	{
		stack->tail->next = tmp;
		stack->tail = tmp;
	}
}

int popStack(Stack* stack)
{
	if (stack->head == NULL) return 0;

	int number = stack->head->data;

	if (stack->head == stack->tail) stack->tail = NULL;

	Element* tmp = stack->head;
	stack->head = stack->head->next;
	free(tmp);

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
	while (stack->head != NULL)
	{
		if (stack->head == stack->tail) stack->tail = NULL;

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