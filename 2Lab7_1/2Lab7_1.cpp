#include<iostream>
#include<time.h>

int* AllocateArray(int rows, int cols)
{
	int* array = (int*)malloc(sizeof(int) * rows * cols);

	return array;
}

int* CreateArray(int* rows, int* cols)
{
	printf("Введите размер массива\n");
	do {
		printf("Введите количество строк [1;1000] = ");
		scanf_s("%i", rows);
	} while (*rows < 1 or *rows > 1000);

	do {
		printf("Введите количество столбцов [1;1000] = ");
		scanf_s("%i", cols);
	} while (*cols < 1 or *cols > 1000);

	printf("\n");

	return AllocateArray(*rows, *cols);
}

void PrintArray(int* array, int rows, int cols)
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
			printf("%5i ", array[i * cols + j]);
		printf("\n");
	}

	printf("\n");
}

void FillArrayRandom(int* array, int rows, int cols) // 1, 2, 3, ...
{
	int a = 0, b = 0;

	srand(time(0));

	printf("Введите диапазон от A до B\n[...,...] = ");
	scanf_s("%i", &a);

	do {
		printf("[%i,...] = ", a);
		scanf_s("%i", &b);
	} while (a > b);

	printf("[%i,%i]\n", a, b);

	for (unsigned int i = 0; i < rows * cols; i++)
		array[i] = rand() % (b - a + 1) + a;
}

int* FillArrayFromTxt(int* rows, int* cols)
{
	FILE* f;
	if (fopen_s(&f, "array.txt", "r") != 0) exit(1);
	fscanf_s(f, "%i%i", rows, cols);
	int* array = AllocateArray(*rows, *cols);
	for (unsigned int i = 0; i < *rows * *cols; i++)
		fscanf_s(f, "%i", &array[i]);

	fclose(f);
	return array;
}

int Task(int* array, int rows, int cols)
{
	int* tmp = AllocateArray(1, cols);

	for (unsigned int i = 0; i < cols; i++)
	{
		int amount = 0;
		for (unsigned int j = 0; j < rows * cols; j += rows)
			amount += array[i + j];
		tmp[i] = amount;
	}

	int max = tmp[0];

	for (unsigned int i = 0; i < cols - 1; i++)
		if (max < tmp[i + 1]) max = tmp[i + 1];

	free(tmp);

	return max;
}

int* Choice(int* array, int* rows, int* cols)
{
	int choice = 0;

	do {
		printf("FILL ARRAY | 1. RANDOM 2. TXT = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			array = CreateArray(rows, cols);
			FillArrayRandom(array, *rows, *cols);
			break;
		case 2:
			array = FillArrayFromTxt(rows, cols);
			break;
		}
	} while (choice != 1 and choice != 2);

	return array;
}

int main()
{
	system("chcp 1251");
	system("cls");

	int rows = 0, cols = 0;
	int* array = NULL;

	array = Choice(array, &rows, &cols);

	printf("\n");

	PrintArray(array, rows, cols);
	printf("\tMax = %i", Task(array, rows, cols));
	free(array);

	return 0;
}

// Вычислить сумму каждого столбца. Среди полученных сумм
// найти максимальное значение.
