#include"RaggedArray.h"

int main()
{
	RaggedArray array;
	
	ChoiceFillRaggedArray(array, "raggedarray.txt", "raggedarray.bin");

	ChoicePrint(array);
	
	/*for (unsigned int i = 4; i <= 12; i+= 2)
		AddNewRowAndColumnInRaggedArray(array, i);*/

	//ChoicePrint(array);

	/*DeleteLastRowAndColumnInRaggedArray(array);
	ChoicePrint(array);*/

	ChoiceInputtingRaggedArray(array, "raggedarray.txt", "raggedarray.bin");
	
	DestroyRaggedArray(array);
	
	if (array.data == NULL) printf("Free ragged array\n");

	//system("pause");
	
	return 0;
}