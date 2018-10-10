// TestApp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cctype>
#include <string.h>
#include <clocale>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <mbstring.h>

char* tolowerstr(char* str)	// достаточно просто переписать
{
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

bool addtofile(char * str)	// достаточно просто переписать
{
	FILE *f = fopen("D:\\record.txt", "a+");
	if (f != NULL)
	{
		time_t t = time(NULL);
		tm* inf = localtime(&t);
		char buf[3] = "";
		_itoa(inf->tm_hour, buf, 10);
		char res[203] = "";
		strcat(res, buf);
		strcat(res, ".");
		_itoa(inf->tm_min, buf, 10);
		strcat(res, buf);
		strcat(res, ".");
		_itoa(inf->tm_sec, buf, 10);
		strcat(res, buf);
		strcat(res, ":  ");
		strcat(res, str);
		strcat(res, "\0");
		fputs(res, f);
		fclose(f);
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int rnd;
	while (1)
	{
		char* str = new char[200];
		scanf("%s", str);
		addtofile(str);
		tolowerstr(str);
		char *tmp = strstr(str, "прив");
		if (tmp)
		{
			rnd = rand() % 10;
			switch (rnd)
			{
			case 0: str = "Здравствуй, приятель."; printf(str); addtofile(str); break;
			case 1: str = "Здарова!"; printf(str); addtofile(str); break;
			case 2: str = "Привет."; printf(str); addtofile(str); break;
			case 3: str = "И тебе не хворать..."; printf(str); addtofile(str); break;
			case 4: str = "Приветствую Вас, пользователь!"; printf(str); addtofile(str); break;
			case 5: str = "Хай!"; printf(str); addtofile(str); break;
			case 6: str = "Добрый день."; printf(str); addtofile(str); break;
			case 7: str = "Hello!"; printf(str); addtofile(str); break;
			case 8: str = "Привет, старик."; printf(str); addtofile(str); break;
			case 9: 
				{
					str = "А мы знакомы?";
					printf(str); 
					addtofile(str);
					scanf("%s", str);
					addtofile(str);
					tolowerstr(str);
					if (strstr(str, "да") || strstr(str, "угу") ||
						strstr(str, "ага") || strstr(str, "yes"))
					{
						str = "Ну тогда привет и тебе.";
						printf(str);
						addtofile(str);
					}
					else
					{
						str = "Иди отсюда!";
						printf(str);
						addtofile(str);
					}
					break;
				}
			}
		}
		else
		{
			str = "Мама не разрешает мне разговаривать с незнакомцами.";
			printf(str);
			addtofile(str);
		}
	}
    return 0;
}

