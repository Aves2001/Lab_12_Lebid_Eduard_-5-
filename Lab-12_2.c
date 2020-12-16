   /*/----------------------!!!----------------------------/*/
  /*/ Before compilation Save with Encoding Windows 1251  /*/
 /*/              Saved in Encoding UTF-8                /*/
/*/-------------------------!!!-------------------------/*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <mem.h>
#include "default_cfg.h"
                                 /////////////////////////////////////////////////////////////
#define _yellow SetColor(14,0); // жовний вивід тексту на екран + чорний фон               //
#define _red SetColor(12,0);   // червоний вивід тексту на екран + чорний фон             //
#define _green SetColor(10,0);// повернення зеленого виводу тексту на екран + чорний фон //
                             /////////////////////////////////////////////////////////////
#define TOP 3
struct date {
	int day;
	char month[20];
	int year;
};

struct bank_db{
	int numm;
	char name[20];
	int summ;
	struct date dt;
};

int main()
{
	start_cfg(); // default_cfg.h
struct bank_db list[] = {
	{0, "Ковач Т.П.", 1, 
	{10, "Грудня", 2019}},
	
	{1, "Малек В.В.", 110,
	{11, "Березня", 2020}},
	
	{2, "Підлобний Б.М.", 820,
	{22, "Квітня", 2020}},
	
	{3, "Руцька К.К.", 45, 
	{15, "Травня", 2020}},
	
	{1, "Малек В.В.", 1000,
	{17, "Грудня", 2020}},

	{1, "Малек В.В.", 180,
	{18, "Грудня", 2020}},

	{0, "Ковач Т.П.", 800, 
	{20, "Грудня", 2020}}
	
};

int N = sizeof(list)/sizeof(list[0]);

	printf("\n|%-9s |%-20s |%-11s |%-24s", "№ рахунку", "прізвище та ініціали", "сума вкладу", "дата проведення операції");
for (int i = 0; i < N; i++)
{
	printf("\n|#%-9d|%-20s |$%-11d|%d %s %d", list[i].numm, list[i].name, list[i].summ, list[i].dt.day, list[i].dt.month, list[i].dt.year);
}

int *summ = (int*)calloc(N, sizeof(int));
int *index = (int*)calloc(N, sizeof(int));

printf("\n");
for (int i = 0; i < N; i++)
{
	index[list[i].numm] = list[i].numm;
	summ[list[i].numm] += 1;
}
int tmp1,tmp2;
for (int i = 1; i < N; i++)
{
	if (summ[i] > summ[i-1])
	{
		tmp1 = summ[i];
		summ[i] = summ[i-1];
		summ[i-1] = tmp1;

		tmp2 = index[i];
		index[i] = index[i-1];
		index[i-1] = tmp2;
	}
}
realloc(summ, sizeof(int)*TOP);
realloc(index, sizeof(int)*TOP);
printf("\n");

// for (int i = 0; i < TOP; i++)
// {
// 	printf("index[%d] = %-10d",i, index[i]);
// 	printf("summ[%d] = %-10d\n",i, summ[i]);
// }
// printf("\n");
free(summ);

printf("\n%-3sТоп три клієнти банку з найбільшою кількістю банківських операцій:","");
printf("\nГ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
printf("\n|%-9s |%-20s |%-11s |%-24s", "№ рахунку", "прізвище та ініціали", "сума вкладу", "дата проведення операції");
int i=0;
// for (int j = 0; j < TOP; j++)
// {
// 	i = index[j];
// 	printf("\n|#%-3d|#%-9d|%-20s |$%-11d|%d %s %d", j+1, list[i].numm, list[i].name, list[i].summ, list[i].dt.day, list[i].dt.month, list[i].dt.year);
// }


for (int K = 0; K < TOP; K++)
{
	for (int j = 0; j < N; j++)
	{
		if (list[j].numm == index[K])
		{
			i = j;
		printf("\n|#%-9d|%-20s |$%-11d|%d %s %d", list[i].numm, list[i].name, list[i].summ, list[i].dt.day, list[i].dt.month, list[i].dt.year);
		}
	}
	printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

free(index);
	end_cfg(); // default_cfg.h
	return 0;
}