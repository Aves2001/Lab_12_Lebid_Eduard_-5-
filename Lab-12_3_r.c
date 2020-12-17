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

void sort_author(struct book *input, int N){
	struct book tmp1;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int i = 1; i < N; i++)
		{
				if (input[i].author[0] < input[i-1].author[0])
				{
					tmp1 = input[i];
					input[i] = input[i-1];
					input[i-1] = tmp1;
					break;
				}
			}
		}
	}

void print(struct book *input, int N){
	printf("\nГ=====================================================================|");
	printf("\n|%-15s |%-20s |%-24s |%-4s|", "Автор", "Книга", "Публікація", "Рік");
	for (int i = 0; i < N; i++)
	{
		printf("\n|=====================================================================|");
		printf("\n|%-15s |%-20s |%-24s |%-4d|", input[i].author, input[i].name_book, input[i].pub, input[i].year);
	}
	printf("\n|=====================================================================|\n");
}

void update_file(struct book *input, int N){
	FILE *outfile;
	outfile = fopen (_file, "w");
	if (outfile == NULL)
	{
		Error_RED();
		fprintf(stderr, "Помилка відкриття файлу\n");
		end_cfg();
		exit (1);
	}
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
	}
	else
	{
		Error_RED();
		printf("помилка запису файлу!\n");
	}
	
	fclose (outfile);
}
int main ()
{
	start_cfg(); // default_cfg.h
	int k = 0;
	int N = 0;
	FILE *infile;
	struct book *input;
	infile = fopen (_file, "r");
	if (infile == NULL)
	{
		Error_RED();
		fprintf(stderr, "Невдалося відкрити файл\n");
		end_cfg(); // default_cfg.h
		exit (1);
	}

	fread(&N, sizeof(int), 1, infile);

	input = (struct book*)calloc(N, sizeof(struct book));

	while(fread(&input[k], sizeof(struct book), 1, infile)){k++;}

	_yellow
	printf("\nВміст файла %s:\n", _file);
	_green
	print(input, N);

	_yellow
	printf("\n\n\nВідсортований масив за прізвищами авторів:\n");
	_green
	sort_author(input, N);
	print(input, N);

	update_file(input, N);

	fclose (infile); 
	end_cfg(); // default_cfg.h
	return 0;
}