#include<iostream>

void randomarray(int array[], int N);

void scanarray(int array[], int N);

void FILEscanarray(int array[], int& N);

int lenghtarr()
{
	int lengthArray;
	do {
		printf("[1, 1000] | Length array = ");
		scanf_s("%i", &lengthArray);
	} while (lengthArray < 1 or lengthArray > 1000);
	return lengthArray;
}

void choice(int array[], int& N)
{
	int c;
	do {
		printf("1.Random 2. Keyboard 3. File = ");

		scanf_s("%i", &c);

		switch (c)
		{
		case 1:
			N = lenghtarr();
			randomarray(array, N);
			break;
		case 2:
			N = lenghtarr();
			scanarray(array, N);
			break;
		case 3:
			FILEscanarray(array, N);
			break;

		default: printf("Error!\n");
		}
	} while (c != 1 and c != 2 and c != 3);
}

void randomarray(int array[], int N)
{
	srand(time(0));
	int a, b;
	printf("[A, B]\nA = ");
	scanf_s("%i", &a);
	printf("B = ");
	scanf_s("%i", &b);
	for (int iteration = 0; iteration < N; iteration++)
		array[iteration] = rand() % (b - a + 1) + a;
}

void scanarray(int array[], int N)
{
	int Narray;
	for (int iteration = 0; iteration < N; iteration++)
	{
		printf("Array[%i] = ", iteration + 1);
		scanf_s("%i", &Narray);
		array[iteration] = Narray;
	}
}

//-----

void FILEscanarray(int array[], int& N)
{
	FILE* Farray;
	if (fopen_s(&Farray, "array.txt", "r") != 0) exit(5);
	fscanf_s(Farray, "%i%*c", &N);
	for (int iteration = 0; iteration < N; iteration++)
		fscanf_s(Farray, "%i", &array[iteration]);
	fclose(Farray);
}

void FILEsavearray(int array[], int N)
{
	FILE* Farray;
	if (fopen_s(&Farray, "sarray.txt", "w") != 0) exit(5);
	fprintf(Farray, "%i\n", N);
	for (int iteration = 0; iteration < N; iteration++)
		fprintf(Farray, "%i ", array[iteration]);
	fclose(Farray);	
}

//-----

void printarray(int array[], int N)
{
	for (int iteration = 0; iteration < N; iteration++)
	{
		printf("Array[%i] = %i\n", iteration + 1, array[iteration]);
	}
}

int counterarray(int array[], int N)
{
	int counter = 0;
	for (int iteration = 0; iteration < N; iteration++)
	{
		if (array[iteration] >= 0) counter++;
	}

	return counter;
}

void numbersarray(int counter)
{
	if (counter == 1) printf("ћассив содержит 1 положительное число\n");
	else if (counter > 1) printf("ћассив содержит более 1 положительного числа\n");
	else printf("ћассив содержит только отрицательные числа\n");
}

void leftarray(int array[], int N)
{
	int tmp = array[0];

	for (int iteration = 0; iteration < N - 1; iteration++)
	{
		array[iteration] = array[iteration + 1];
	}

	array[N - 1] = tmp;
}

int main()
{
	system("chcp 1251");
	system("cls");

	const int N = 1000;
	int array[N], counter = 0, lengthArray = 0;

	choice(array, lengthArray);

	counter = counterarray(array, lengthArray);

	numbersarray(counter);

	leftarray(array, lengthArray);

	printarray(array, lengthArray);

	FILEsavearray(array, lengthArray);
}

// ќпределить, содержитс€ ли в массиве ровно одно положительное число. ÷иклически сдвинуть все элементы массива на 1 элемент влево.
