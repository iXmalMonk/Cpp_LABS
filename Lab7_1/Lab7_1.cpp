#include<iostream>

int main()
{
	system("chcp 1251");

	float a, b = 1;
	printf("������� ����� � = ");
	scanf_s("%f", &a);

	while (a > sqrt(b))
	{
		printf("%f = %f\n", sqrt(b), b);
		b++;
	}
}

// ������� ��� �����, ������� ��������� ����� A, �� ������������������ sqrt(2), sqrt(3), sqrt(4) � �.�.