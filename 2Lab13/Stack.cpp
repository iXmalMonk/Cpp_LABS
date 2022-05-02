#include<iostream>
#include"Stack.h"

void initStack(Stack* stack, int length)
{
	if (stack->data == NULL)
	{
		stack->data = (int*)malloc(sizeof(int) * length);
		stack->length = length;
	}
	else printf("\n\tStack is init\n");
}
	
void pushStack(Stack* stack, int number)
{
	if (stack->top >= stack->length)
	{
		stack->length += 10;
		stack->data = (int*)realloc(stack->data, sizeof(int) * stack->length);
	}
	
	stack->top++;

	stack->data[stack->top] = number;
}

int popStack(Stack* stack)
{
	if (stack->top >= 0) return stack->data[stack->top--];
	else return NULL;
}

int peekStack(Stack* stack)
{
	if (stack->top >= 0) return stack->data[stack->top];
	else return NULL;
}

void clearStack(Stack* stack)
{
	stack->top = -1;
}

void printStack(Stack const* stack)
{
	printf("\nStack\n");
	for (int i = 0; i <= stack->top; i++)
		printf("[%i] - %i\n", i + 1, (stack->data)[i]);
	printf("\n");
}

void deInitStack(Stack* stack)
{
	if (stack->data) free(stack->data);

	stack->data = NULL;
	stack->length = 0;
	stack->top = -1;
}

bool checkIfStackIsEmpty(Stack* stack)
{
	if (stack->top == -1) return true;
	else return false;
}