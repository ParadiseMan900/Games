#include <stdio.h>
#include <iostream>
#include <stdlib.h>
int main()
{
	int i, j, l[4], b = 0, o, k[4], s = 0, z = 0, igra = 0, g = 0;
	char p;
	setlocale(LC_ALL, "RUS");
	printf("	**********************\n");
	printf("	*Игра \"Быки и коровы\"*\n");
	printf("	**********************\n");
	printf("	                      Версия 1.5\n\n");
	while (igra == 0)
	{
		printf("Что вы хотите сделать?\n");
		printf("* Начать играть (1).\n");
		printf("* Посмотреть правила игры (2).\n");
		printf("* Выйти из игры (Любой символ).\n");
		scanf_s("%c", &p);
		getchar();
		switch (p)
		{
		case '2':
			printf(" * Быки и коровы — логическая игра, в ходе которой за 9 попыток игрок должен определить, что задумала программа.\n");
			printf(" * Программа задумывает и записывает тайное 4-значное число с неповторяющимися цифрами.\n * Игрок делает первую попытку отгадать число. Попытка — это 4-значное число с неповторяющимися цифрами, сообщаемое программе. Программа сообщает в ответ, сколько цифр угадано без совпадения с их позициями в тайном числе (то есть количество коров) и сколько угадано вплоть до позиции в тайном числе (то есть количество быков).\n * Игра продолжается до тех пор, пока попытки не кончатся или число не будет отгаданно.\n\n");
			break;
		case '1':
			srand(time(NULL));
			l[0] = rand() % 9 + 1;
			for (i = 1; i < 4;)
			{
				l[i] = rand() % 10;
				for (j = 0; j < i;)
				{
					if (l[j] == l[i]) j = 900;
					else j++;
				}
				if (j != 900) i++;
			}
			printf("Четырёхзначное число задуманно.\n");
			while (b < 9)
			{
				b++;
				printf("Назовите ваше предположение (Цифры не должны повторятся). У вас есть %d попыток.\n", 10-b);
				printf("*(%d)* ", b);
				scanf_s("%d", &o);
				s = 0;
				z = 0;
				if ((o / 1000 == 0) || (o / 10000 != 0))
				{
					printf("	Введите \"Четырёхзначное\" число c неповторяющимеся цифрами. -1 попытка.\n");
					continue;
				}
					for (i = 0; i < 4; i++)
					{
						k[i] = o % 10;
							o = o / 10;
					}
					for (i = 1; i < 4; i++)
					{
						for (j = 0; j < i; j++)
						{
							if (k[i] == k[j]) g = 900;
						}
					}
					if (g == 900)
					{
						g = 0;
						printf("	Введите четырёхзначное число с \"Неповторяющимеся цифрами\". -1 попытка.\n");
						continue;
					}
					for (i = 0; i < 4; i++)
					{
						for (j = 0; j < 4; j++)
						{
							if (k[i] == l[j]) s++;
						}
					}
					for (i = 0; i < 4; i++)
					{
						if (k[3 - i] == l[i]) z++;
					}
					s -= z;
					if (z == 4)
					{
						printf("*******************************************************\n");
						printf("* Поздравляю! Вы угадали число. Количество попыток: %d *\n", b);
						printf("*******************************************************\n");
						system("pause");
						return 0;
					}
					else printf("	Количество коров: %d, количество быков %d\n", s, z);
			}
			printf("\n* К сожалению вы проиграли, использовав все 9 попыток. Загаданное число: %d%d%d%d *\n", l[0], l[1], l[2], l[3]);
			system("pause");
			return 0;
		default:
			printf("\nЗавершение программы");
			for (i = 0; i < 3; i++)
			{
				printf(".");
				system("timeout 1 > nul");
			}
			printf("\n");
			return 0;
		}
	}	
}

