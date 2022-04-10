#include <iostream>
#include <Windows.h>

int RandomNumber(int start, int end)
{
	return rand() % (end - start + 1) + start;
}

void SetConsoleColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(-11), color);
}