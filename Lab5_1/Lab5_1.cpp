#include<iostream>

int main()
{
	system("chcp 1251");

	float a, b;

	printf("������� ����� ����� = ");
	scanf_s("%f", &a);

	if (a > 0)
		b = sqrt(a);
	else
		b = a * 3;
	printf("����� = %.3f", b);
}

// ���� ����� �����. ���� ��� �������������, ������� �� ���� ������, � ��������� ������ �������� �� 3.