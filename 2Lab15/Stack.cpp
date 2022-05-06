#include<iostream>
#include"Stack.h"

// Метод, вставка в очередь нового элемента на указанную позицию (метод Insert)

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