#ifndef __STACK_H__
#define __STACK_H__

struct Element
{
	int data = 0;
	Element* next = NULL;
};

struct Stack
{
	Element* head = NULL, * tail = NULL;
};

void pushStack(Stack* stack, int number);

int popStack(Stack* stack);

int peekStack(Stack* stack);

void printStack(Stack const* stack);

void clearStack(Stack* stack);

bool checkIfStackIsEmpty(Stack* stack);

#endif