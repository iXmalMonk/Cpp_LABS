#include<iostream>

int main()
{
	system("chcp 1251");

	int a, b, n, sum = 0;

	printf("A = ");
	scanf_s("%i", &a);
	printf("B = ");
	scanf_s("%i", &b);
	
	do
	{
		printf("N = ");
		scanf_s("%i", &n);
	} while (n <= 0);

	for (int i = 0; n > i; i++)
	{
		printf("%i\n", a);
		sum += a;
		a *= b;
	}
	printf("����� = %i", sum);
}

// ����� ������ ������ ���� � ����������� �������������� ����������. ��������� ����� ������ n �� ������.
