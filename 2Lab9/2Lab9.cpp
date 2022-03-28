#include"RaggedArray.h"

int main()
{
	RaggedArray array;
	
	ChoiceFillRaggedArray(array, "raggedarray.txt", "raggedarray.bin");

	ChoicePrint(array);

	DeleteRowInRaggedArray(array, 3);

	ChoicePrint(array);

	ChoiceInputtingRaggedArray(array, "raggedarray.txt", "raggedarray.bin");
	
	DestroyRaggedArray(array);
	
	if (array.data == NULL) printf("Free ragged array\n");

	system("pause");
	
	return 0;
}