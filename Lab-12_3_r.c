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
#define _file "book.dat" // тут можна поміняти імя файла
struct book
{
	char author[50]; // Автор
	char name_book[50]; // Назва книиги
	char pub[50]; // видавництво
	int year; // рік видання
};
void print(struct book *input, int N); // Вивід таблиці на екран
void sort_author(struct book *input, int N); // Сортування таблиці по прізвищям авторів
void update_file(struct book *input, int N); // Запис відсортованої таблиці у файл

int main ()
{
	start_cfg(); // default_cfg.h
	int k = 0; //індекс рядка який потрібно зчитати з файла, а також використовується для переходу до наступного рядка
	int N = 0; //Кількість рядків в таблиці
	FILE *infile; // Вказівник на файл який читається
	struct book *input; //Масив в який будуть зберігатись рядки таблиці
	infile = fopen (_file, "r"); //відкриття файла в режимі читання
	if (infile == NULL)
	{
		Error_RED();
		fprintf(stderr, "Невдалося відкрити файл\n");
		end_cfg(); // default_cfg.h
		exit (1);
	}

	fread(&N, sizeof(int), 1, infile); //Читаєм з файла кількість рядків таблиці

	input = (struct book*)calloc(N, sizeof(struct book)); // і виділяєм для них память

	while(fread(&input[k], sizeof(struct book), 1, infile)){k++;} // читання всіх рядків з файла у масив

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

	fclose (infile); //закриття файла
	end_cfg(); // default_cfg.h
	return 0;
}
///////////////////////////////////////////////////////////////////////
void print(struct book *input, int N){
	printf("\nГ=====================================================================|");
	printf("\n|%-15s |%-20s |%-24s |%-4s|", "Автор", "Книга", "Публікація", "Рік");
	for (int i = 0; i < N; i++) // вивід на екран рядків таблиці
	{
		printf("\n|=====================================================================|");
		printf("\n|%-15s |%-20s |%-24s |%-4d|", input[i].author, input[i].name_book, input[i].pub, input[i].year);
	}
	printf("\n|=====================================================================|\n");
}
///////////////////////////////////////////////////////////////////////
void sort_author(struct book *input, int N){
	struct book tmp1; // тимчасовий рядок в який буде зберігатись рядок таблиці при сортуванні
	for (int i = N - 1; i >= 0; i--)
	{
		for (int i = 1; i < N; i++)
		{
				if (input[i].author[0] < input[i-1].author[0]) // Сортування таблиці по першій літері першого стовпця
				{
					tmp1 = input[i];
					input[i] = input[i-1];
					input[i-1] = tmp1;
					break;
				}
			}
		}
	}
///////////////////////////////////////////////////////////////////////
void update_file(struct book *input, int N){
	FILE *outfile; // Вказівник на файл
	outfile = fopen (_file, "w"); //відкриття для запису (для оновлення даних)
	if (outfile == NULL)
	{
		Error_RED();
		fprintf(stderr, "Помилка відкриття файлу\n");
		end_cfg();
		exit (1);
	}
	fwrite (&N, sizeof(int), 1, outfile); //Збереження кількості рядків таблиці у файл
	for (int i = 0; i < N; i++) // Збереження самих рядків
	{
		fwrite (&input[i], sizeof(struct book), 1, outfile);	
	}
	if(fwrite != 0)
	{
		_yellow
		printf("\n\nВміст до файлу успішно написано!\n");
		_green
	}
	else
	{
		Error_RED();
		printf("помилка запису файлу!\n");
	}
	
	fclose (outfile); // закриття файла
}