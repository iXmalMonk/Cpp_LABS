#include <iostream>

#define N 256

int main()
{
#pragma region TASK_2
	char task2_str[N];
	int task2_counter = 0;

	gets_s(task2_str);

	for (unsigned int i = 0; task2_str[i] != '\0'; i++)
	{
		if (task2_str[i] == '+') task2_counter++;
		else if (task2_str[i] == '-') task2_counter++;
		else if (task2_str[i + 1] == '0') task2_counter++;
	}

	printf("%s\n", task2_str);
	printf("%i\n", task2_counter);
#pragma endregion


	return 0;
}

// ������� �� ������ ��� �����, � ������� ����������� �� �����
// ���� ��������� ����.

// ���� ������. ���������� ����� ���������� �������� '+' � '-' �
// ���, � ����� ���������� ����� ��������, ����� ������� �������
// ����� ����.

// ��� email � ������. ����������, �������� �� �� ����������
// (������� ������� @ � �����, ������� �� ����� ���� �������� �����
// ��������� ����� � �.�.).