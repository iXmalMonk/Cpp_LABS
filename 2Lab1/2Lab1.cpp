#include <iostream>

void Range(int* a_p, int* b_p)
{
	printf("������� �������� [A;B]\nA = ");
	scanf_s("%d", a_p);

	do {
		printf("B = ");
		scanf_s("%d", b_p);
	} while (*a_p > *b_p);
}

void AmountRange(int* a_p, int* b_p, int* amount_p)
{
	for (int i = *a_p; i <= *b_p; i++)
		*amount_p += i;
}

void ProductRange(int* a_p, int* b_p, int* product_p)
{
	for (int i = *a_p; i <= *b_p; i++)
		*product_p *= i;
}

int main()
{
	system("chcp 1251");
	system("cls");

	int a, b, amount = 0, product = 1;

	Range(&a, &b);

	system("cls");

	printf("[%d;%d]\n", a, b);

	AmountRange(&a, &b, &amount);

	printf(" Amount = %d\n", amount);

	ProductRange(&a, &b, &product);

	printf("Product = %d", product);
}

// ��������� ����� � ������������ ���� ����� �� � �� �.
