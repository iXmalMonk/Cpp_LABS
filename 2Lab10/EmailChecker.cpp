#include <iostream>

/*
1. Имя пользователя должно начинаться с буквы
2. Имя пользователя должно заканчиваться буквой или цифрой
3. Длина имени пользователя минимум 4 символа
4. Разрешенные специальные символы в имени пользователя [ - _ . ]
5. В имени пользователя не могут идти подряд специальные символы [ - _ . ]
0. ('@')
6. Имя сервера должно начинаться с буквы или цифры
7. Имя сервера должно заканчиваться буквой или цифрой
8. Разрешенные специальные символы в имени сервера [ - _ ]
9. В имени сервера не могут идти подряд специальные символы [ - _ ]
0. ('.')
10. Длина домена минимум 2 символа
11. В домене могут использоваться только буквы.
*/

struct Email {
	bool username_first_symbol = false; // Username has to start with a letter.

	bool username_last_symbol = false; // Username has to end with a letter or a number.

	bool dog_symbol = false; // Email has a dog symbol.
	int dog_index = 0;

	bool username_length = false; // Username has minimum four symbols.

	bool username_correct = false; // Username only has letters, numbers, ('-'), ('_') and ('.').
	bool username_correct_repeat_symbols = true;

	bool servername_first_symbol = false; // Servername has to start with a letter or a number.

	bool servername_last_symbol = false; // Servername has to end with a letter or a number.

	bool dot_symbol = false; // Email has a dot symbol.
	int dot_index = 0;

	bool servername_correct = false; // Servername only has letters, numbers, ('-') and ('_').
	bool servername_correct_repeat_symbols = true;

	bool domen_length = false; // Domen has minimum two symbols.

	bool domen_correct = false; // Domen only has letters.

	char correct_symbols[3] = { '-', '_', '.' }; // 0 - | 1 _ | 2 .
};

void UsernameFirstSymbol(char str[], Email& email)
{
	if ((str[0] >= 'a' and str[0] <= 'z') or (str[0] >= 'A' and str[0] <= 'Z')) email.username_first_symbol = true;
}

void UsernameLastSymbol(char str[], Email& email)
{
	if ((str[email.dog_index - 1] >= 'a' and str[email.dog_index - 1] <= 'z') or (str[email.dog_index - 1] >= 'A' and str[email.dog_index - 1] <= 'Z')
		or (str[email.dog_index - 1] >= '0' and str[email.dog_index - 1] <= '9')) email.username_last_symbol = true;
}

void DogSymbolAndIndex(char str[], Email& email)
{
	for (int i = 0; !email.dog_symbol and str[i] != '\0'; i++)
		if (str[i] == '@')
		{
			email.dog_symbol = true;
			email.dog_index = i;
		}
}

void UsernameLength(char str[], Email& email)
{
	for (int i = 0; i < email.dog_index; i++)
		if (i == 3) email.username_length = true;
}

void UsernameCorrect(char str[], Email& email)
{
	for (int i = 1; i < email.dog_index; i++)
	{
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				if ((str[i] == email.correct_symbols[j]) and (str[i + 1] == email.correct_symbols[k])) email.username_correct_repeat_symbols = false;

		if ((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z') or (str[i] >= '0' and str[i] <= '9')
			or str[i] == email.correct_symbols[0] or str[i] == email.correct_symbols[1] or str[i] == email.correct_symbols[2]) email.username_correct = true;
		else email.username_correct = false;

		if (!email.username_correct_repeat_symbols or !email.username_correct) break;
	}
}

void ServernameFirstSymbol(char str[], Email& email)
{
	if ((str[email.dog_index + 1] >= 'a' and str[email.dog_index + 1] <= 'z') or (str[email.dog_index + 1] >= 'A' and str[email.dog_index + 1] <= 'Z')
		or (str[email.dog_index + 1] >= '0' and str[email.dog_index + 1] <= '9')) email.servername_first_symbol = true;
}

void ServernameLastSymbol(char str[], Email& email)
{
	if ((str[email.dot_index - 1] >= 'a' and str[email.dot_index - 1] <= 'z') or (str[email.dot_index - 1] >= 'A' and str[email.dot_index - 1] <= 'Z')
		or (str[email.dot_index - 1] >= '0' and str[email.dot_index - 1] <= '9')) email.servername_last_symbol = true;
}

void DotSymbolAndIndex(char str[], Email& email)
{
	for (int i = email.dog_index + 1; !email.dot_symbol and str[i] != '\0'; i++)
		if (str[i] == '.')
		{
			email.dot_symbol = true;
			email.dot_index = i;
		}
}

void ServernameCorrect(char str[], Email& email)
{
	for (int i = email.dog_index + 1; i < email.dot_index; i++)
	{
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				if ((str[i] == email.correct_symbols[j]) and (str[i + 1] == email.correct_symbols[k])) email.servername_correct_repeat_symbols = false;

		if ((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z') or (str[i] >= '0' and str[i] <= '9')
			or str[i] == email.correct_symbols[0] or str[i] == email.correct_symbols[1]) email.servername_correct = true;
		else email.servername_correct = false;

		if (!email.servername_correct_repeat_symbols or !email.servername_correct) break;
	}
}

void DomenLength(char str[], Email& email)
{
	for (int i = email.dot_index + 1, j = 0; str[i] != '\0'; i++, ++j)
		if (j == 1) email.domen_length = true;
}

void DomenCorrect(char str[], Email& email)
{
	for (int i = email.dot_index + 1; str[i] != '\0'; i++)
		if ((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z')) email.domen_correct = true;
		else
		{
			email.domen_correct = false;
			break;
		}
}

void CheckEmail(char str[])
{
	Email email;

	UsernameFirstSymbol(str, email);
	if (email.username_first_symbol)
	{
		DogSymbolAndIndex(str, email);
		if (email.dog_symbol)
		{
			UsernameLastSymbol(str, email);
			if (email.username_last_symbol)
			{
				UsernameLength(str, email);
				if (email.username_length)
				{
					UsernameCorrect(str, email);
					if (email.username_correct and email.username_correct_repeat_symbols)
					{
						ServernameFirstSymbol(str, email);
						if (email.servername_first_symbol)
						{
							DotSymbolAndIndex(str, email);
							if (email.dot_symbol)
							{
								ServernameLastSymbol(str, email);
								if (email.servername_last_symbol)
								{
									ServernameCorrect(str, email);
									if (email.servername_correct and email.servername_correct_repeat_symbols)
									{
										DomenLength(str, email);
										if (email.domen_length) DomenCorrect(str, email);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if (email.domen_correct) printf("Email correct\n");
	else printf("Email incorrect\n");
}