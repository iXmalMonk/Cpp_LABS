//#pragma once
#include<iostream>

struct RaggedArray {
	int** data = NULL;
};

void CreateRaggedArrayWithKeyboard(RaggedArray& array);

void FillRaggedArrayWithRandomNumbers(RaggedArray& array);

void PrintRaggedArray(RaggedArray array);

void PrintSizeRaggedArray(RaggedArray array);

void DestroyRaggedArray(RaggedArray& array);

void CreateRaggedArrayFromTxtFile(RaggedArray& array, const char* filenameTxt);

void InputtingRaggedArrayInTxtFile(RaggedArray array, const char* filenameTxt);

void CreateRaggedArrayFromBinFile(RaggedArray& array, const char* filenameBin);

void InputtingRaggedArrayInBinFile(RaggedArray array, const char* filenameBin);

void ChoiceFillRaggedArray(RaggedArray& array, const char* filenameTxt, const char* filenameBin);

void ChoiceInputtingRaggedArray(RaggedArray array, const char* filenameTxt, const char* filenameBin);

void ChoicePrint(RaggedArray array);

//==================================================

void AddNewRowAndColumnInRaggedArray(RaggedArray& array, int columns);

void DeleteLastRowAndColumnInRaggedArray(RaggedArray& array);