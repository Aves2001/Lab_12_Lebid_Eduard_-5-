   /*/----------------------!!!----------------------------/*/
  /*/ Before compilation Save with Encoding Windows 1251  /*/
 /*/              Saved in Encoding UTF-8                /*/
/*/-------------------------!!!-------------------------/*/
#include <stdio.h>
#include "default_cfg.h"
#include <stdlib.h>
#include <string.h>
                                 /////////////////////////////////////////////////////////////
#define _yellow SetColor(14,0); // жовний вивід тексту на екран + чорний фон               //
#define _red SetColor(12,0);   // червоний вивід тексту на екран + чорний фон             //
#define _green SetColor(10,0);// повернення зеленого виводу тексту на екран + чорний фон //
                             /////////////////////////////////////////////////////////////
#define _file "book.dat"

struct book
{
	int id;
	char author[50];
	char name_book[50];
	char pub[50];
	int year;
};

int main ()
{
	start_cfg(); // default_cfg.h
	FILE *outfile;
	outfile = fopen (_file, "w");
	if (outfile == NULL)
	{
		Error_RED();
		fprintf(stderr, "Помилка відкриття файлу\n");
		end_cfg();
		exit (1);
	}

	struct book input[] = {
		{1, "Франко І.", "«Захар Беркут»", "7 КЛАС (2017-2018 н. р.)", 2020},
		{2, "Чайковський А.", "«За сестрою»", "7 КЛАС (2017-2018 н. р.)", 2020},
		{3, "Стельмах М.", "«Гуси-лебеді летять»", "7 КЛАС (2017-2018 н. р.)", 2020},
		{4, "Тютюнник Г.", "«Климко»", "7 КЛАС (2017-2018 н. р.)", 2020}
	};

	int N = sizeof(input)/sizeof(input[0]); // Кількість рядків в таблиці
	
	fwrite (&N, sizeof(int), 1, outfile);
	
	for (int i = 0; i < N; i++)
	{
		fwrite (&input[i], sizeof(struct book), 1, outfile);	
	}

	if(fwrite != 0)
	{
		_yellow
		printf("\n\nвміст до файлу успішно написано!\n");
		_green
	}else
		{
			Error_RED();
			printf("помилка запису файлу!\n");
		}
	fclose (outfile);
	end_cfg(); // default_cfg.h
	return 0;
}