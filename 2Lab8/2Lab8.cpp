#include<iostream>
#include<time.h>
#include<Windows.h>

//#define OUTPUT_HANDLE -11				// this
										// or
constexpr auto OUTPUT_HANDLE = -11;		// this

// TERMINATE_SYMBOL = NULL

struct RaggedArray {
	int** data = NULL;
};

/*
int InputRows()
{
	int rows = 0;

	system("cls");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

	printf("\tRows\n");
	
	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\tRange\n\t[1;500]\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

	do {
		printf("Numbers of rows = ");
		scanf_s("%i", &rows);
	} while (rows < 1 or rows > 500);

	system("cls");

	return rows;
}
*/

/*
int InputCols(int rows)
{
	int cols = 0;

	system("cls");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

	printf("\tColumns\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\tRange\n\t[1;500]\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

	do {
		printf("Numbers of columns %i = ", rows);
		scanf_s("%i", &cols);
	} while (cols < 1 or cols > 500);

	system("cls");

	return cols;
}
*/


void CreateRaggedArrayWithKeyboard(RaggedArray& array)
{
	int rows = 0, cols = 0;

	//rows = InputRows();

	//
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

	printf("\tRows\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\tRange\n\t[1;500]\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

	do {
		printf("Numbers of rows = ");
		scanf_s("%i", &rows);
	} while (rows < 1 or rows > 500);

	system("cls");

	rows += 1;
	//

	array.data = (int**)malloc(sizeof(int*) * rows);

	//
	rows -= 1;
	//

	array.data[rows] = NULL;

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		//cols = InputCols(i + 1);

		//
		SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

		printf("\tColumns\n");

		SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

		printf("\tRange\n\t[1;500]\n");

		SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

		do {
			printf("Numbers of columns %i = ", i + 1);
			scanf_s("%i", &cols);
		} while (cols < 1 or cols > 500);

		cols += 1;
		//

		array.data[i] = (int*)malloc(sizeof(int) * cols);

		//
		cols -= 1;
		//

		array.data[i][cols] = NULL;

		//
		system("cls");
		//
	}
}

void FillRaggedArrayWithRandomNumbers(RaggedArray& array)
{
	srand(time(NULL));

	int A = 0, B = 0;

	system("cls");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

	printf("\tRandom numbers\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\tRange\n\t[A;B] | 0 < A \n");	// [1;B] because TERMINATE_SYMBOL = NULL

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

	do {
		printf("A = ");
		scanf_s("%i", &A);
	} while (1 > A);

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\n\t[%i;B]\n\n", A);

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

	do {
		printf("B = ");
		scanf_s("%i", &B);
	} while (A > B);

	for (unsigned int i = 0; array.data[i] != NULL; i++)
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			array.data[i][j] = rand() % (B - A + 1) + A;

	system("cls");
}

void PrintRaggedArray(RaggedArray array)
{
	int counter = 0;

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

	printf("\tRagged array\n\n");

	for (unsigned int i = 0; array.data[i] != NULL; i++)
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			if (counter < j) counter = j;

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\t    ");

	for (unsigned int i = 0; i <= counter; i++)
		printf("%5i", i + 1);

	printf("\n");

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

		printf("\t%3i ", i + 1);

		SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			printf("%5i", array.data[i][j]);
		printf("\n");
	}

	printf("\n");
}

void PrintSizeRaggedArray(RaggedArray array)
{
	int rows = 0, cols = 0;

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

	printf("\tSize ragged array\n");

	while (array.data[rows] != NULL) rows++;

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\tRows\n\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 10);

	printf("\tNumber of rows = %3i\n\n", rows);

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\tColumns\n\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 10);

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		cols = 0;
		while (array.data[i][cols] != NULL) cols++;
		printf("\tNumber of columns %3i = %i\n", i + 1, cols);
	}

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

	printf("\n");
}

void DestroyRaggedArray(RaggedArray &array)
{
	for (unsigned int i = 0; array.data[i] != NULL; i++)
		free(array.data[i]);
	free(array.data);

	array.data = NULL;
}

// rows
// cols1 number1 number2 ... numberN
// ... 
// colsN number1 number2 ... numberN

void CreateRaggedArrayFromTxtFile(RaggedArray& array, const char* filenameTxt)
{
	int rows = 0, cols = 0;

	FILE* txt;

	if (fopen_s(&txt, filenameTxt, "rt") != 0) exit(1);

	fscanf_s(txt, "%i", &rows);

	rows += 1;

	array.data = (int**)malloc(sizeof(int*) * rows);

	rows -= 1;

	array.data[rows] = NULL;

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		fscanf_s(txt, "%i", &cols);

		cols += 1;

		array.data[i] = (int*)malloc(sizeof(int) * cols);

		cols -= 1;

		array.data[i][cols] = NULL;
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			fscanf_s(txt, "%i", &array.data[i][j]);
	}

	fclose(txt);
}

void InputtingRaggedArrayInTxtFile(RaggedArray array, const char* filenameTxt)
{
	int rows = 0, cols = 0;

	FILE* txt;

	if (fopen_s(&txt, filenameTxt, "wt") != 0) exit(1);

	while (array.data[rows] != NULL) rows++;

	fprintf(txt, "%i\n", rows);

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		cols = 0;
		while (array.data[i][cols] != NULL) cols++;
		fprintf(txt, "%i ", cols);
		for (unsigned int j = 0; array.data[i][j] != NULL; j++)
			fprintf(txt, "%i ", array.data[i][j]);
		fprintf(txt, "\n");
	}

	fclose(txt);
}

// rows
// cols1 number1 number2 ... numberN
// ... 
// colsN number1 number2 ... numberN

void CreateRaggedArrayFromBinFile(RaggedArray& array, const char* filenameBin)
{
	int rows = 0, cols = 0;

	FILE* bin;

	if (fopen_s(&bin, filenameBin, "rb") != 0) exit(1);

	fread(&rows, sizeof(int), 1, bin);

	rows += 1;

	array.data = (int**)malloc(sizeof(int*) * rows);

	rows -= 1;

	array.data[rows] = NULL;

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		fread(&cols, sizeof(int), 1, bin);

		cols += 1;

		array.data[i] = (int*)malloc(sizeof(int) * cols);

		cols -= 1;

		array.data[i][cols] = NULL;
		fread(array.data[i], sizeof(int), cols, bin);
	}

	fclose(bin);
}

void InputtingRaggedArrayInBinFile(RaggedArray array, const char* filenameBin)
{
	int rows = 0, cols = 0;

	FILE* bin;

	if (fopen_s(&bin, filenameBin, "wb") != 0) exit(1);

	while (array.data[rows] != NULL) rows++;

	fwrite(&rows, sizeof(int), 1, bin);

	for (unsigned int i = 0; array.data[i] != NULL; i++)
	{
		cols = 0;
		while (array.data[i][cols] != NULL) cols++;
		fwrite(&cols, sizeof(int), 1, bin);
		fwrite(array.data[i], sizeof(int), cols, bin);
	}

	fclose(bin);
}

void ChoiceFillRaggedArray(RaggedArray& array, const char* filenameTxt, const char* filenameBin)
{
	int choice = 0;

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

	printf("\tFill ragged array\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\t[1] Keyboard\n\t[2] Txt\n\t[3] Bin\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

	do {
		printf("[...] = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			CreateRaggedArrayWithKeyboard(array);
			FillRaggedArrayWithRandomNumbers(array);
			break;
		case 2:
			CreateRaggedArrayFromTxtFile(array, filenameTxt);
			break;
		case 3:
			CreateRaggedArrayFromBinFile(array, filenameBin);
			break;
		}
		
	} while (choice != 1 and choice != 2 and choice != 3);

	system("cls");
}

void ChoiceInputtingRaggedArray(RaggedArray array, const char* filenameTxt, const char* filenameBin)
{
	int choice = 0;

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

	printf("\tInputting ragged array\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

	printf("\t[1] Txt\n\t[2] Bin\n\t[3] Txt&Bin\n\t[4] None\n");

	SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

	do {
		printf("[...] = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			InputtingRaggedArrayInTxtFile(array, filenameTxt);
			break;
		case 2:
			InputtingRaggedArrayInBinFile(array, filenameBin);
			break;
		case 3:
			InputtingRaggedArrayInTxtFile(array, filenameTxt);
			InputtingRaggedArrayInBinFile(array, filenameBin);
		}

	} while (choice != 1 and choice != 2 and choice != 3 and choice != 4);

	system("cls");
}

void ChoicePrint(RaggedArray array)
{
	int choice = 0;

	do {
		SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 12);

		printf("\tPrint ragged array\n");

		SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 11);

		printf("\t[1] Array\n\t[2] Size array\n\t[3] Array&Size array\n\t[4] Exit\n");

		SetConsoleTextAttribute(GetStdHandle(OUTPUT_HANDLE), 7);

		printf("[...] = ");
		scanf_s("%i", &choice);

		system("cls");

		switch (choice)
		{
		case 1:
			system("cls");
			PrintRaggedArray(array);
			break;
		case 2:
			system("cls");
			PrintSizeRaggedArray(array);
			break;
		case 3:
			system("cls");
			PrintRaggedArray(array);
			PrintSizeRaggedArray(array);
		}

	} while (choice != 4);

	system("cls");
}

int main()
{
	//system("chcp 1251 > nul");

	RaggedArray array;

	ChoiceFillRaggedArray(array, "raggedarray.txt", "raggedarray.bin");

	ChoicePrint(array);

	ChoiceInputtingRaggedArray(array, "raggedarray.txt", "raggedarray.bin");

	DestroyRaggedArray(array);

	//if (array.data == NULL and array.cols == NULL and array.rows == 0) printf("Free ragged array");

	return 0;
}

// Массив представляется указателем на вектор указателей на
// строки. Количество строк определяется терминальным символом.
// Количество элементов строки определяется терминальным символом.
// Память выделяется для каждой конструкции отдельно.