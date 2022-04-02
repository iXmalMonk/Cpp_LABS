#include <iostream>
#include "EmailChecker.h"

#define N 256

int StrCounterPlusMinusZero(char str[])
{
	int counter = 0;

	for (unsigned int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '+') counter++;
		else if (str[i] == '-') counter++;
		else if (str[i + 1] == '0') counter++;
	}

	return counter;
}

int main()
{
	char str_pmz[N];
	printf("Enter string: ");
	gets_s(str_pmz);
	printf("%i\n", StrCounterPlusMinusZero(str_pmz));

	char email[N];
	printf("Enter e-mail: ");
	gets_s(email);
	CheckEmail(email);

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