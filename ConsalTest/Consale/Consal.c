// библиотеки
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// управл¤ющие консолью библиотеки
#include <windows.h>
#include <conio.h>

#define MAIN_MENU_SIZE 3
#define ALG_MENU_SIZE 3
#define SEARCH_MENU_SIZE 3
#define SORT_MENU_SIZE 2
#define SETTINGS_MENU_SIZE 3

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
void constractMenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos) {
	// объявление переменных
	int iKey; // переменная для фиксации нажатой клавиши
	COORD cursorPos; // управление положением курсора, чтобы менять выводимый текст
	// инициализация (заполнение значениями) переменных
	*choose_pos = 0;
	/* 1. вывод меню с переключением */
	// сброс консоли в стартовое положение
	system("cls");
	iKey = 67;
	cursorPos = (COORD) { 0, 0 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	// контроль нажатия клавиш
	while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
		switch (iKey) {
		case KEY_ARROW_UP:
			(*choose_pos)--;
			break;
		case KEY_ARROW_DOWN:
			(*choose_pos)++;
			break;
		}
		system("cls");
		// зацикливание перелистывания меню
		if (*choose_pos < 0) { *choose_pos = menu_size - 1; }
		if (*choose_pos > menu_size - 1) { *choose_pos = 0; }
		for (int i = 0; i < menu_size; i++) {
			cursorPos = (COORD) { 3, i };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("%s \n", menu_names[i]);
		}
		// обозначение выбранной позиции
		cursorPos = (COORD) { 0, * choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("<<", iKey);
		cursorPos = (COORD) { strlen(menu_names[*choose_pos]) + 3 + 1, * choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf(">>");
		// ожидание нового нажатия клавиши
		iKey = _getch();
	}
}

void input(int* arr, int* size)
{
	system("cls");
	printf( "Введите размер масива: ");
	scanf_s("%d", size);
	
	arr = (int)malloc(sizeof(int) * *size);
	for (int i = 0;i < *size;i++)
	{
		printf("\nВведите число №%d\n");
		scanf_s("%d",&arr[i]);
	}
	system("pause");
	system("cls");
}


void PrintArray(int* f[], int size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		printf("%d\n", f[i]);
	}
	system("pause");
	system("cls");
}

void EaseSearch(int* array,int ArraySize) {
	int SerchItem=0;
	int i=0;
	int SearchFlag = 0;
	system("cls");
	printf("ВВедите искомый элемент\n");
	scanf_s("%d",&SerchItem);



	for (i = 0;i < ArraySize;i++) {
		if (array[i] == SerchItem) {
			//printf("%d\n", array[i]);
			SearchFlag = 1;
			break;
		}
	}
	if (SearchFlag == 1) {
		printf("Искомый элемент под индексом %d(Начиная с 0)\n",i);
	}
	else {
		printf("Искомый элемент не найден\n");
	}
	system("pause");
	system("cls");
}

void SortArray(int* num, int size)
{
	// Для всех элементов
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
		{
			if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
			{
				int temp = num[j - 1]; // меняем их местами
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}
	}
}

int binarysearch(int a, int mass[], int n)
{
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (a < mass[middle])
			high = middle - 1;
		else if (a > mass[middle])
			low = middle + 1;
		else
			return middle;
	}
	return -1;
}

int BinSearch(int* Array, int ArraySize)
{
	int SearchItem = 0, ItemIndex = 0;
	system("cls");
	printf("ВВедите искомое число\n");
	scanf_s("%d",&SearchItem);
	ItemIndex = binarysearch(SearchItem, Array, ArraySize);
	if (ItemIndex >-1) {
		printf("Искомый элемент под индексом %d(начиная с 0)", ItemIndex);
	}
	else {
		printf("Искомый элемент не найден");
	}
	system("pause");
	system("cls");
}

int main() {
	system("title Application");
	SetConsoleCP(1251);         
	SetConsoleOutputCP(1251);   
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	system("cls");
	
	int ArraySize=3;
	int* array[3] = {1,11,10};
	int SearchItem;
	int choose_pos = 0;                 
	int exit_flag = 0;                    
	char* MainMenu[MAIN_MENU_SIZE] = { "Алгоритмы","Настройки","Выход" };
	char* AlgMenu[ALG_MENU_SIZE] = { "Поиск","Сортировки","Взад" };
	char* SerchMenu[SEARCH_MENU_SIZE] = { "Наивный поиск","Бинарный поиск","Взад" };
	char* SortMenu[SORT_MENU_SIZE] = { "Пузырьковая сортировка","Взад" };
	char* SettingstMenu[SETTINGS_MENU_SIZE] = { "Задать массив","Посмотрать текущий массив","Назад" };

	while (exit_flag==0) {
		constractMenu(hStdOut, MainMenu, MAIN_MENU_SIZE, &choose_pos);
		switch (choose_pos) {
		case 0:
			constractMenu(hStdOut, AlgMenu, ALG_MENU_SIZE, &choose_pos);
			switch (choose_pos) {
			case 0:
				constractMenu(hStdOut, SerchMenu, SEARCH_MENU_SIZE, &choose_pos);
				switch (choose_pos) {
				case 0:
					EaseSearch(&array, ArraySize);
					break;
				case 1:
					SortArray(&array, ArraySize);
					BinSearch(&array, ArraySize);
					break;
				case 2:
					break;
				}
				break;
			case 1:
				constractMenu(hStdOut, SortMenu, SORT_MENU_SIZE, &choose_pos);
				switch (choose_pos)
				{
				case 0:
					SortArray(&array, ArraySize);
					break;
				case 1:
					break;
				}
				break;
			case 2:
				break;
			}
			break;
		case 1:
			constractMenu(hStdOut, SettingstMenu, SETTINGS_MENU_SIZE, &choose_pos);
			switch (choose_pos){
			case 0:
				free(array);
				input(&array,&ArraySize);
				break;
			case 1:
				PrintArray(&array, ArraySize);
				break;
			case 2:
				break;
			}
			break;
		case 2:
			exit_flag = 1;
			break;
		}
	}
	return 0;
}
