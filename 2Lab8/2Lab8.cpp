#include<iostream>
#include<time.h>

// TERMINATE_SYMBOL = NULL

struct RaggedArray {
	int rows = 0;
	int* cols = NULL;
	int** data = NULL;
};

int InputRows()
{
	int rows = 0;

	system("cls");

	printf("\tДиапазон\n\t[1;500]\n");

	do {
		printf("Введите количество строк = ");
		scanf_s("%i", &rows);
	} while (rows < 1 or rows > 500);

	system("cls");

	return rows;
}

int InputCols()
{
	int cols = 0;

	printf("\tДиапазон\n\t[1;500]\n");

	do {
		printf("Введите количество элементов строки = ");
		scanf_s("%i", &cols);
	} while (cols < 1 or cols > 500);

	system("cls");

	return cols;
}

void CreateRaggedArrayWithKeyboard(RaggedArray& array)
{
	int cols = 0;

	array.rows = InputRows();

	array.data = (int**)malloc(sizeof(int*) * (array.rows + 1));
	array.data[array.rows] = NULL;

	array.cols = (int*)malloc(sizeof(int) * (array.rows + 1));
	array.cols[array.rows] = NULL;

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		cols = InputCols();
		array.data[i] = (int*)malloc(sizeof(int) * (cols + 1));
		array.data[i][cols] = NULL;
		array.cols[i] = cols;
	}
}

void FillRaggedArrayWithRandomNumbers(RaggedArray& array)
{
	srand(time(NULL));

	int B = 0;

	printf("\tРандомные числа\n\tДиапазон\n\t[1;B]\n"); // [1;B] because TERMINATE_SYMBOL = NULL

	do {
		printf("B = ");
		scanf_s("%i", &B);
	} while (1 > B);

	printf("[1;%i]\n", B);

	for (unsigned int i = 0; array.data[i] != NULL; i++)
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			array.data[i][j] = rand() % B + 1;

	system("cls");
}

void PrintRaggedArray(RaggedArray array)
{
	system("cls");

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		printf("\t");
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			printf("%3i", array.data[i][j]);
		printf("\n");
	}

	printf("\n");
}

void PrintSizeRaggedArray(RaggedArray array)
{
	printf("\tКоличество строк = %i\n", array.rows);

	for (unsigned int i = 0; array.cols[i] != NULL; i++)
		printf("\tКоличество элементов строки %i = %i\n", i + 1, array.cols[i]);

	printf("\n");
}

void DestroyRaggedArray(RaggedArray &array)
{
	for (unsigned int i = 0; array.data[i] != NULL; i++)
		free(array.data[i]);
	free(array.data);
	free(array.cols);
	array.data = NULL, array.cols = NULL; array.rows = 0;
}

// rows
// cols1 number1 number2 ... numberN
// ... 
// colsN number1 number2 ... numberN

void CreateRaggedArrayFromTxtFile(RaggedArray& array)
{
	FILE* txt;
	if (fopen_s(&txt, "raggedarray.txt", "rt") != 0) exit(1);

	fscanf_s(txt, "%i", &array.rows);

	array.data = (int**)malloc(sizeof(int*) * (array.rows + 1));
	array.data[array.rows] = NULL;

	array.cols = (int*)malloc(sizeof(int) * (array.rows + 1));
	array.cols[array.rows] = NULL;

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		fscanf_s(txt, "%i", &array.cols[i]);
		array.data[i] = (int*)malloc(sizeof(int) * (array.cols[i] + 1));
		array.data[i][array.cols[i]] = NULL;
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			fscanf_s(txt, "%i", &array.data[i][j]);
	}

	fclose(txt);
}

void InputtingRaggedArrayInTxtFile(RaggedArray array)
{
	FILE* txt;
	if (fopen_s(&txt, "raggedarray.txt", "wt") != 0) exit(1);

	fprintf(txt, "%i\n", array.rows);

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		fprintf(txt, "%i ", array.cols[i]);
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			fprintf(txt, "%i ", array.data[i][j]);
		fprintf(txt, "\n");
	}

	fclose(txt);
}

void CreateRaggedArrayFromBinFile(RaggedArray& array)
{
	FILE* bin;
	if (fopen_s(&bin, "raggedarray.bin", "rb") != 0) exit(1);

	fread(&array.rows, sizeof(int), 1, bin);

	array.data = (int**)malloc(sizeof(int*) * (array.rows + 1));
	array.data[array.rows] = NULL;

	array.cols = (int*)malloc(sizeof(int) * (array.rows + 1));
	array.cols[array.rows] = NULL;

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		fread(&array.cols[i], sizeof(int), 1, bin);
		array.data[i] = (int*)malloc(sizeof(int) * (array.cols[i] + 1));
		array.data[i][array.cols[i]] = NULL;
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			fread(&array.data[i][j], sizeof(int), 1, bin);
	}

	fclose(bin);
}

void InputtingRaggedArrayInBinFile(RaggedArray array)
{
	FILE* bin;
	if (fopen_s(&bin, "raggedarray.bin", "wb") != 0) exit(1);

	fwrite(&array.rows, sizeof(int), 1, bin);

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		fwrite(&array.cols[i], sizeof(int), 1, bin);
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			fwrite(&array.data[i][j], sizeof(int), 1, bin);
	}

	fclose(bin);
}

void ChoiceFillRaggedArray(RaggedArray& array)
{
	int choice = 0;

	do {
		printf("\t[1] Keyboard\n\t[2] Txt\n\t[3] Bin\n[...] = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			CreateRaggedArrayWithKeyboard(array);
			FillRaggedArrayWithRandomNumbers(array);
			break;
		case 2:
			CreateRaggedArrayFromTxtFile(array);
			break;
		case 3:
			CreateRaggedArrayFromBinFile(array);
			break;
		}
		
	} while (choice != 1 and choice != 2 and choice != 3);
}

void ChoiceInputtingRaggedArray(RaggedArray array)
{
	int choice = 0;

	do {
		printf("\t[1] Txt\n\t[2] Bin\n[...] = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			InputtingRaggedArrayInTxtFile(array);
			break;
		case 2:
			InputtingRaggedArrayInBinFile(array);
			break;
		}

	} while (choice != 1 and choice != 2);
}

int main()
{
	system("chcp 1251 > nul");

	RaggedArray array;

	ChoiceFillRaggedArray(array);

	PrintRaggedArray(array);

	PrintSizeRaggedArray(array);

	ChoiceInputtingRaggedArray(array);

	DestroyRaggedArray(array);

	system("cls");

	//if (array.data == NULL and array.cols == NULL and array.rows == 0) printf("Free ragged array");

	return 0;
}

// Массив представляется указателем на вектор указателей на
// строки. Количество строк определяется терминальным символом.
// Количество элементов строки определяется терминальным символом.
// Память выделяется для каждой конструкции отдельно.