#include <iostream>
#include <stdio.h>
#include <math.h>

int Proverka(char mas[][3], int i, char perem)
{
    int s = 0;
    for (i = 0; i < 3; i++)
    {
            if ((mas[i][0]==perem) && (mas[i][1] == perem) && (mas[i][2] == perem)) s = 1;
            if ((mas[0][i] == perem) && (mas[1][i] == perem) && (mas[2][i] == perem)) s = 1;
    }
    if ((mas[0][0] == perem) && (mas[1][1] == perem) && (mas[2][2] == perem)) s = 1;
    if ((mas[0][2] == perem) && (mas[1][1] == perem) && (mas[2][0] == perem)) s = 1;
    return s;
}
int main()
{
    int s = 0;
    int r = 7;
    int i,j,csifra;
    char mas[3][3];
    char perem;
    setlocale(LC_ALL, "RUS");
    printf(" * * * * * * * * *\n");
    printf(" *Крестики-Нолики*\n");
    printf(" * * * * * * * * *\n\n");
    printf("Игровые обозначения:\n");
    printf("В пустое место на поле (*) нужно поставить 3 символа в ряд (X или O).\n\n");
    printf("Поле для крестиков-ноликов:\n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mas[i][j] = '*';
            printf("%c ", mas[i][j]);
        }
        if (i == 1) printf("== "); else printf("   ");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", r);
            r++;
        }
        r -= 6;
        printf("\n");
    }
    printf("______________________________________________________________________\n");
    while (s < 9)
    {
        csifra = 0;
        s++;
        if (s % 2 == 1) perem = 'X'; else perem = 'O';
        chek:
        printf("\nВыберете расположения \"%c\" на цифровой клавиатуре: ", perem);
        scanf_s("%d", &csifra);
        printf("\n");
        csifra--;
        
        if ((csifra > 8) || (csifra < 0))
        {
            printf("Ошибка! Неккоректный ввод\n");
            if(getchar() != '\n') while (getchar() != '\n');
            goto chek;      //Проверка на принадлежность отрезку от 1 до 9
        }
        if ((mas[abs(2 - (csifra / 3))][csifra % 3] == '*')) mas[abs(2 - (csifra / 3))][csifra % 3] = perem; else
        {
            printf("*Выбери незанятое место*\n", perem);
            goto chek;
        }
        if (Proverka(mas, i, perem) == 1)
        {
            system("cls");
            printf("Победил игрок %c!\n\n", perem);
            s = 10;
        }

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%c ", mas[i][j]);
            }
            printf("\n");
        }
    }
    if (s == 9)
    {
        printf("\nНичья!\n");
    }
    printf("\n");
    system("pause");
}
