#include<iostream>
#include<time.h>

const int ROWS = 100;
const int COLS = 100;

void InputRowsColsInArray(int& r, int& c)
{
	do {
		printf("[1, 100] Введите число строк: ");
		scanf_s("%i", &r);
	} while (r < 1 or r > 100);

	do {
		printf("[1, 100] Введите число столбцов: ");
		scanf_s("%i", &c);
	} while (c < 1 or c > 100);
}

void FillArrayFromKeyboard(double array[ROWS][COLS], int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			printf("Array[%i][%i] = ", i + 1, j + 1);
			scanf_s("%lf", &array[i][j]);
		}
}

void FillArrayRandom(double array[ROWS][COLS], int r, int c)
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

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			array[i][j] = rand() % (b - a + 1) + a;
}

void FillArrayFromTask(double array[ROWS][COLS], int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (i > j)
				array[i][j] = cos(i) * double(i + j) / (2.0 * i + 3.0 * j);
			else if (i == j)
				array[i][j] = 3;
			else
				array[i][j] = sin(2 * i + j);
		}
}

void InputArrayFromTxt(double array[ROWS][COLS], int& r, int& c)
{
	FILE* file;
	if (fopen_s(&file, "array.txt", "r") != 0) exit(5);
	fscanf_s(file, "%i%i", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			fscanf_s(file, "%lf", &array[i][j]);
	fclose(file);
}

void SaveArrayInTxt(double array[ROWS][COLS], int& r, int& c)
{
	FILE* file;
	if (fopen_s(&file, "array.txt", "w") != 0) exit(5);
	fprintf(file, "%i %i\n", r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			fprintf(file, "%lf ", array[i][j]);
		fprintf(file, "\n");
	}
	fclose(file);
}

void InputArrayFromBin(double array[ROWS][COLS], int& r, int& c)
{
	FILE* file;
	if (fopen_s(&file, "array.bin", "rb") != 0) exit(5);
	fread(&r, sizeof(int), 1, file);
	fread(&c, sizeof(int), 1, file);
	for (int i = 0; i < r; i++)
		fread(&array[i], sizeof(double), c, file);
	fclose(file);
}

void SaveArrayInBin(double array[ROWS][COLS], int& r, int& c)
{
	FILE* file;
	if (fopen_s(&file, "array.bin", "wb") != 0) exit(5);
	fwrite(&r, sizeof(int), 1, file);
	fwrite(&c, sizeof(int), 1, file);
	for (int i = 0; i < r; i++)
		fwrite(&array[i], sizeof(double), c, file);
	fclose(file);
}

void PrintArray(double array[ROWS][COLS], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%10.3lf ", array[i][j]);

		printf("\n");
	}
}

double ArrayTask(double array[ROWS][COLS], int r)
{
	double amount = 1;
	for (int i = 0; i < r; i++)
		if (array[i][r - i - 1] > 0)
			for (int j = 0; j < r; j++)
				amount *= array[j][r - i - 1];
	return amount;
}

void ChoiceInputArray(double array[ROWS][COLS], int& r, int& c)
{
	int choice = 0;

	do {
		printf("FILL ARRAY | 1. Keyboard 2. Random 3. File 4. Bin 5. Task = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			InputRowsColsInArray(r, c);
			FillArrayFromKeyboard(array, r, c);
			break;
		case 2:
			InputRowsColsInArray(r, c);
			FillArrayRandom(array, r, c);
			break;
		case 3:
			InputArrayFromTxt(array, r, c);
			break;
		case 4:
			InputArrayFromBin(array, r, c);
			break;
		case 5:
			InputRowsColsInArray(r, c);
			FillArrayFromTask(array, r, c);
			break;

		default: printf("Error!\n");
		}
	} while (choice != 1 and choice != 2 and choice != 3 and choice != 4 and choice != 5);
}

void ChoiceSaveArray(double array[ROWS][COLS], int& r, int& c)
{
	int choice = 0;

	do {
		printf("SAVE ARRAY | 1. TXT 2. BIN 3. TXT AND BIN 4. Don't save = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			SaveArrayInTxt(array, r, c);
			break;
		case 2:
			SaveArrayInBin(array, r, c);
			break;
		case 3:
			SaveArrayInTxt(array, r, c);
			SaveArrayInBin(array, r, c);
			break;
		case 4:
			return;
			break;

		default: printf("Error!\n");
		}
	} while (choice != 1 and choice != 2 and choice != 3);
}

int main()
{
	system("chcp 1251");
	system("cls");

	double array[ROWS][COLS];
	int r = 0, c = 0;

	ChoiceInputArray(array, r, c);

	PrintArray(array, r, c);

	ArrayTask(array, r);

	printf("Amount = %.3lf\n", ArrayTask(array, r));

	ChoiceSaveArray(array, r, c);
}

// a(i,j)
// i < j sin(2 * i + j)
// i = j 3
// i > j cos(i) * (i + j) / (2 * i + 3 * j)

//Вычислить произведение элементов тех столбцов матрицы, в которых положителен элемент побочной диагонали.