#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b, c;

	printf("������� r < R\n����� �� = 3.14\n");

	printf("���������� ������ r (�) = ");
	scanf_s("%lf", &a);
	printf("������� ������ R (�) = ");
	scanf_s("%lf", &b);

	if (b > a)
	{
		c = 3.14 * (b * b - a * a);

		printf("S ������ (�^2) = %.3lf; r = %.3lf, R = %.3lf\n", c, a, b);
	}
}

// ���������� ������� ������, ���������� ������ �������� ����� r, � ������� � ��������� ����� R (R > r).