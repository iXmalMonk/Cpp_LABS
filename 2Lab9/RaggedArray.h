#ifndef __RAGGEDARRAY_H__
#define __RAGGEDARRAY_H__

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

int GetRows(RaggedArray array);

void AddNewRowInRaggedArray(RaggedArray& array, int columns);

void DeleteLastRowInRaggedArray(RaggedArray& array);

void DeleteRowInRaggedArray(RaggedArray& array, int number);

#endif