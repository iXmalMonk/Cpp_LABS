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

char* GetWord(char str[], int start, int stop)
{
	if (stop < start) return NULL;

	char* str_temp = (char*)malloc(sizeof(char) * (stop - start + 2));
	str_temp[stop - start + 1] = '\0';

	for (int i = start, j = 0; i < stop + 1; i++, j++)
		str_temp[j] = str[i];
	
	return str_temp;
}

void RemoveSmallLetterWords(char str[])
{
	char str_new[N] = { '\0' };
	int k = 0;
	bool c = false;
	// Outputing words
	for (int start = 0, stop = 0; str[stop] != '\0'; stop++)
	{
		// COUNTER
		int counter = 1;
		// COUNTER
		if (str[stop + 1] == ' ' or str[stop + 1] == '\0')
		{
			char* str_temp = GetWord(str, start, stop);
			// COUNTER
			if (str_temp != NULL)
			{
				char letter = str_temp[0];
				for (int i = 1; str_temp[i] != '\0'; i++)
					if (str_temp[i] != letter)
					{
						char temp = str_temp[i];

						for (int j = i; str_temp[j] != '\0'; j++)
							if (str_temp[j] == temp) str_temp[j] = letter;

						counter++;
					}

				// NEW STR
				if (counter >= 3)
				{
					free(str_temp);
					str_temp = NULL;
					char* str_temp = GetWord(str, start, stop);

					for (int i = 0; str_temp[i] != '\0'; i++)
					{
						str_new[k++] = str_temp[i];
					}
					str_new[k++] = ' ';
					c = true;
				}
				// NEW STR
			}
			// COUNTER
			free(str_temp);
			start = stop + 2;
		}
	}
	// Outputing words
	if (c)
	{
		// Remove last space
		for (int i = 0; str_new[i] != '\0'; i++)
			if (str_new[i + 1] == '\0') str_new[i] = '\0';
		// Remove last space

		// STR
		for (int i = 0; str_new[i] != '\0'; i++)
		{
			str[i] = str_new[i];
			if (str_new[i + 1] == '\0') str[i + 1] = '\0';
		}
		// STR
	}
	else str[0] = '\0';
}

int main()
{
	/*char str_pmz[N];
	printf("Enter string: ");
	gets_s(str_pmz);
	printf("%i\n", StrCounterPlusMinusZero(str_pmz));*/

	char email[N];
	while (true)
	{
		printf("Enter e-mail: ");
		gets_s(email);
		if (email[0] == '0') break;
		CheckEmail(email);
	}

	/*char str[N];
	printf("Enter string: ");
	gets_s(str);
	RemoveSmallLetterWords(str);
	printf("%s\n", str);*/

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