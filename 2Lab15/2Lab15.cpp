#include<iostream>
#include"Stack.h"

void pushNumberInStackWithTxtFile(const char* filename, Stack* first_stack, Stack* second_stack)
{
	FILE* f;
	int file_length = 0, number = 0;
	if (fopen_s(&f, filename, "rt") != 0) exit(1);
	fscanf_s(f, "%i", &file_length);
	for (int i = 0; i < file_length; i++)
	{
		fscanf_s(f, "%i", &number);
		if (number >= 0) pushStack(first_stack, number);
		else pushStack(second_stack, number);
	}
}

int main()
{
	Stack first_stack, second_stack;

	pushNumberInStackWithTxtFile("numbers.txt", &first_stack, &second_stack);

	printStack(&first_stack);
	printf("\n");
	printStack(&second_stack);

	clearStack(&first_stack);
	clearStack(&second_stack);

	return 0;
}

// ƒан файл из целых чисел. »спользу€ очередь, за один
// просмотр файла напечатать сначала все отрицательные числа, затем
// все положительные числа, сохран€€ исходный пор€док в каждой
// группе.
