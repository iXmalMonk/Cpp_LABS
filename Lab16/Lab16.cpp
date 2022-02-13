#include<iostream>

struct Product
{
	char name[50];
	double cost;
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
		scanf_s("%s%lf%i", P[i].name, 50, &P[i].cost, &P[i].count);
	}
}

void FILEscanProduct(Product P[], int& NProduct) // NProduct -> name cost count
{
	FILE* FProduct;
	if (fopen_s(&FProduct, "product.txt", "r") != 0) exit(5);
	fscanf_s(FProduct, "%i%*c", &NProduct);
	for (int i = 0; i < NProduct; i++)
		fscanf_s(FProduct, "%s%lf%i", P[i].name, 50, &P[i].cost, &P[i].count);
	fclose(FProduct);
}

void printProduct(Product P[], int NProduct)
{
	for (int i = 0; i < NProduct; i++)
	{
		printf("Product [%i] | name = %s, cost = %.2f, count = %i\n", i + 1, P[i].name, P[i].cost, P[i].count);
	}
}

void FILEscanProductBIN(Product P[], int& NProduct)
{
	FILE* FProduct;
	if (fopen_s(&FProduct, "product.bin", "rb") != 0) exit(5);
	fread(&NProduct, sizeof(int), 1, FProduct);
	for (int i = 0; i < NProduct; i++)
		fread(&P[i], sizeof(struct Product), 1, FProduct);
	fclose(FProduct);
}

void inputProduct(Product P[], int& NProduct)
{
	int c = 0;
	do {
		printf("1.Keyboard 2. File 3. Bin = ");
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
		case 3:
			FILEscanProductBIN(P, NProduct);
			break;

		default: printf("Error!\n");
		}
	} while (c != 1 and c != 2 and c != 3);
}

int amountProduct(Product P[], int NProduct)
{
	double amount = 0;
	for (int i = 0; i < NProduct; i++)
		amount += P[i].cost * P[i].count;
	return amount;
}

void FILEprintProduct(Product P[], int NProduct)
{
	FILE* FProduct;
	if (fopen_s(&FProduct, "sproduct.txt", "w") != 0) exit(5);
	fprintf(FProduct, "%i\n", NProduct);
	for (int i = 0; i < NProduct; i++)
		fprintf(FProduct, "%s %.2f %i\n", P[i].name, P[i].cost, P[i].count);
	fclose(FProduct);
}

void FILEprintProductBIN(Product P[], int NProduct)
{
	FILE* FProduct;
	if (fopen_s(&FProduct, "product.bin", "wb") != 0) exit(5);
	fwrite(&NProduct, sizeof(int), 1, FProduct);
	for (int i = 0; i < NProduct; i++)
		fwrite(&P[i], sizeof(struct Product), 1, FProduct);
	fclose(FProduct);
}

void saveProduct(Product P[], int NProduct)
{
	int c = 0;
	do {
		printf("Save | 1. TXT 2. BIN 3. (1&2) = ");
		scanf_s("%i", &c);

		switch (c)
		{
		case 1:
			FILEprintProduct(P, NProduct);
			break;
		case 2:
			FILEprintProductBIN(P, NProduct);
			break;
		case 3:
			FILEprintProduct(P, NProduct);
			FILEprintProductBIN(P, NProduct);
			break;

		default: printf("Error!\n");
		}
	} while (c != 1 and c != 2 and c != 3);
}

int main()
{
	system("chcp 1251");
	system("cls");

	const int N = 100;
	int NProduct = 0;
	double amount = 0;
	Product P[N];

	inputProduct(P, NProduct);

	printProduct(P, NProduct);

	amount = amountProduct(P, NProduct);

	printf("Amount = %.2f\n", amount);

	saveProduct(P, NProduct);
}

// Пусть задан список товаров (название, цена, количество единиц товара на складе), количество которых задает пользователь. 
// Определить общую стоимость товаров на складе. 

