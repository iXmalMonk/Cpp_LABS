#ifndef __STACK_H__
#define __STACK_H__

struct Stack
{
	int* data = NULL;
	int length = 0;
	int top = -1;
};

void initStack(Stack* stack, int length);

void pushStack(Stack* stack, int number);

int popStack(Stack* stack);

int peekStack(Stack* stack);

void clearStack(Stack* stack);

void printStack(Stack const* stack);

void deInitStack(Stack* stack);

bool checkIfStackIsEmpty(Stack* stack);

#endif

