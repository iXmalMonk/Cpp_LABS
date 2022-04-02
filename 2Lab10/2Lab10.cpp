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

// ������� �� ������ ��� �����, � ������� ����������� �� �����
// ���� ��������� ����.

// ���� ������. ���������� ����� ���������� �������� '+' � '-' �
// ���, � ����� ���������� ����� ��������, ����� ������� �������
// ����� ����.

// ��� email � ������. ����������, �������� �� �� ����������
// (������� ������� @ � �����, ������� �� ����� ���� �������� �����
// ��������� ����� � �.�.).