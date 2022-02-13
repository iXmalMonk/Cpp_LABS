#include<iostream>

struct Product
{
	char name[50];
	float cost;
	int count;
};

int countsProduct()
{
	int NProduct = 0;
	do {
		printf("[1, 100] | Products = ");
		scanf_s("%i", &NProduct);
	} while (NProduct < 1 or NProduct > 100);
	return NProduct;
}

void scanProduct(Product P[], int NProduct)
{
	for (int i = 0; i < NProduct; i++)
	{
		scanf_s("%s%f%i", P[i].name, 50, &P[i].cost, &P[i].count);
	}
}

void FILEscanProduct(Product P[], int& NProduct) // NProduct -> name cost count
{
	FILE* FProduct;
	if (fopen_s(&FProduct, "product.txt", "r") != 0) exit(5);
	fscanf_s(FProduct, "%i%*c", &NProduct);
	for (int i = 0; i < NProduct; i++)
		fscanf_s(FProduct, "%s%f%i", P[i].name, 50, &P[i].cost, &P[i].count);
	fclose(FProduct);
}

void printProduct(Product P[], int NProduct)
{
	for (int i = 0; i < NProduct; i++)
	{
		printf("Product [%i] | name = %s, cost = %.2f, count = %i\n", i + 1, P[i].name, P[i].cost, P[i].count);
	}
}

void inputProduct(Product P[], int& NProduct)
{
	int c = 0;
	do {
		printf("1.Keyboard 2. File = ");
		scanf_s("%i", &c);

		switch (c)
		{
		case 1:
			NProduct = countsProduct();
			scanProduct(P, NProduct);
			break;
		case 2:
			FILEscanProduct(P, NProduct);
			break;

		default: printf("Error!\n");
		}
	} while (c != 1 and c != 2);
}

int amountProduct(Product P[], int NProduct)
{
	float amount = 0;
	for (int i = 0; i < NProduct; i++)
		amount += P[i].cost * P[i].count;
	return amount;
}

void FILEprintProduct(Product P[], int NProduct, float amount)
{
	FILE* FProduct;
	if (fopen_s(&FProduct, "sproduct.txt", "w") != 0) exit(5);
	fprintf(FProduct, "%i\n", NProduct);
	for (int i = 0; i < NProduct; i++)
		fprintf(FProduct, "%s %.2f %i\n", P[i].name, P[i].cost, P[i].count);
	fprintf(FProduct, "Amount = %.2f", amount);
	fclose(FProduct);
}

int main()
{
	system("chcp 1251");
	system("cls");

	const int N = 100;
	int NProduct = 0;
	float amount = 0;
	Product P[N];

	inputProduct(P, NProduct);

	printProduct(P, NProduct);

	amount = amountProduct(P, NProduct);

	printf("Amount = %.2f", amount);

	FILEprintProduct(P, NProduct, amount);
}

// Пусть задан список товаров (название, цена, количество единиц товара на складе), количество которых задает пользователь. 
// Определить общую стоимость товаров на складе. 