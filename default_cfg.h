#include <windows.h>
// #include <conio.h>

void SetColor(int text, int background) // для установки кольору тексту і фона
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Error_RED() // виводить на екран Error червоним кольором із звуком
{
	SetColor(12,0);
	printf("\r\n\a[Error] ");
	SetColor(10,0);
}

void start_cfg() // стандартні настройки при запуску програми
{
	system("color 0a"); // встановлює зелений текст і чорний фон

// Встановлення кодової сторінки 1251
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
//-------------------------------
}

void end_cfg() // стандартні настройки при завершенні програми
{
	SetColor(10,0); // встановлює зелений текст і чорний фон
	// Повертає стандартне значення кодової сторінки
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	// getch();
	printf("\r\n\n");
	system("pause"); // пауза для того щоби можна було ознайомитись з результатом роботи програми
}