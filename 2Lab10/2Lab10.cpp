#include <iostream>

#define N 256

int main()
{
#pragma region TASK_2
	char task2_str[N];
	int task2_counter = 0;

	gets_s(task2_str);

	for (unsigned int i = 0; task2_str[i] != '\0'; i++)
	{
		if (task2_str[i] == '+') task2_counter++;
		else if (task2_str[i] == '-') task2_counter++;
		else if (task2_str[i + 1] == '0') task2_counter++;
	}

	printf("%s\n", task2_str);
	printf("%i\n", task2_counter);
#pragma endregion


	return 0;
}

// Удалить из текста все слова, в которых встречается не более
// двух различных букв.

// Дана строка. Определить общее количество символов '+' и '-' в
// ней, а также количество таких символов, после которых следует
// цифра ноль.

// Дан email в строке. Определить, является ли он корректным
// (наличие символа @ и точки, наличие не менее двух символов после
// последней точки и т.д.).