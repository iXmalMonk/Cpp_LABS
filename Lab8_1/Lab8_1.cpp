#include<iostream>
#include<limits.h>

int main()
{
	system("chcp 1251");

	int a, min = 2147483647;
	
	do {
		printf("����� = ");
		scanf_s("%i", &a);
		if (min > a && a % 2 != 0) min = a;
	} while (a > 0);

	printf("����������� �������� ����� = %i", min);
}

/*�������� ��������� ����������� ������������ ��������� ����� ��
������������������ ������������� �����, �������� � ����������.
���� ������ ��������� ����� ����, ��� ������������ ������ 0 ��� ����� ������������� �����.*/