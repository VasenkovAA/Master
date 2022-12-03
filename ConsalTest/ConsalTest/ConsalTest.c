
// библиотеки
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

// управл¤ющие консолью библиотеки
#include <windows.h>
#include <conio.h>

#define MENU_SIZE 3

// основные ключи, которые могут пригодитьс¤

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

#define ListMenuLength 5

// объ¤вление главной функции
int main() {
	// настройки

	// задаЄм название консольного окна
	system("title Application");

	// устанавливаем взаимодействие с русскими буквами
	SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода
	//setlocale(LC_ALL,"rus");
	//system("chcp 866");
	// получаем дескриптор окна дл¤ обращени¤ к консоли
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// отключение мигани¤ курсора в консоли (в нашем меню курсор лишний)
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	// задаЄм серый фон дл¤ окна консоли
	SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	// очищаем экран, чтобы настройка цвета применилась
	system("cls");

	// объ¤вление переменных
	int choose_pos;                    // переменна¤ дл¤ хранени¤ выбранного пункта меню
	int iKey;                          // переменна¤ дл¤ фиксации нажатой клавиши
	int exit_flag;                     // флаг на завершение программы
	COORD cursorPos;                   // управление положением курсора, чтобы мен¤ть выводимый текст

	char* MainMenu[MENU_SIZE] = { "Алгоритмы", "Настройки", "Выход" };
	char* ListMenu[ListMenuLength] = { "MainMenu","AlgMenu","SetMenu","SortMenu","SearchMenu" };
	int ListMenuPos = 0;

	char* SortMenu[2] = { "Пузырьковая сортировка", "Назад" };
	char* AlgMenu[3] = { "Поиск", "Сортировки", "Назад" };
	char* SetMenu[3] = { "Задать массив", "Посмотреть текущий массив", "Назад" };
	char* SearchMenu[3] = { "Наивный поиск", "Бинарный поиск", "В зад" };

	// инициализаци¤ (заполнение значени¤ми) переменных
	exit_flag = 0;
	choose_pos = 0;

	while (!exit_flag) {
		/* 1. вывод меню с переключением */

		// сброс консоли в стартовое положение
		system("cls");
		iKey = 67;
		cursorPos = (COORD) { 0, 0 };
		SetConsoleCursorPosition(hStdOut, cursorPos);

		// контроль нажати¤ клавиш
		while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
			switch (iKey) {
			case KEY_ARROW_UP:
				choose_pos--;
				break;
			case KEY_ARROW_DOWN:
				choose_pos++;
				break;
			}

			system("cls");

			// зацикливание перелистывани¤ меню
			if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
			if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

			switch (ListMenuPos) {
			case 0:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////ОТРИСОВКА  MainMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", MainMenu[i]);
				}
				break;
			case 1:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////ОТРИСОВКА AlgMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", AlgMenu[i]);
				}
				break;
			case 2:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////ОТРИСОВКА SetMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", SetMenu[i]);
				}
				break;
			case 3:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////ОТРИСОВКА SortMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", SortMenu[i]);
				}
				break;
			case 4:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////ОТРИСОВКА SearchMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", SearchMenu[i]);
				}
				break;

			}

			// обозначение выбранной позиции
			cursorPos = (COORD) { 0, choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("<<", iKey);
			cursorPos = (COORD) { strlen(MainMenu[choose_pos]) + 3 + 1, choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf(">>");

			// ожидание нового нажати¤ клавиши
			iKey = _getch();
		}

		/* 2. основна¤ часть программы */
		switch (ListMenuPos) {
		case 0:
			switch (choose_pos) {
			case 0:
				system("cls");
				ListMenuPos = 1;
				break;
			case 1:
				system("cls");
				ListMenuPos = 2;
				break;
			case 2:
				exit_flag = 1;
				break;
			}
			break;
		case 1:
			switch (choose_pos) {
			case 0:
				system("cls");
				printf("Game part in development\n");
				system("pause");
				break;
			case 1:
				system("cls");
				printf("Settings part in development\n");
				system("pause");
				break;
			case 2:
				exit_flag = 1;
				break;
			}
			break;
		case 2:
			switch (choose_pos) {
			case 0:
				system("cls");
				printf("Game part in development\n");
				system("pause");
				break;
			case 1:
				system("cls");
				printf("Settings part in development\n");
				system("pause");
				break;
			case 2:
				exit_flag = 1;
				break;
			}
			break;
		case 3:
			switch (choose_pos) {
			case 0:
				system("cls");
				printf("Game part in development\n");
				system("pause");
				break;
			case 1:
				system("cls");
				printf("Settings part in development\n");
				system("pause");
				break;
			case 2:
				exit_flag = 1;
				break;
			}
			break;

		case 4:
			switch (choose_pos) {
			case 0:
				system("cls");
				printf("Game part in development\n");
				system("pause");
				break;
			case 1:
				system("cls");
				printf("Settings part in development\n");
				system("pause");
				break;
			case 2:
				exit_flag = 1;
				break;
			}
			break;
		}
	}

	// вывод результата
	system("cls");
	printf("Goodbay!\n");

	// завершение программы
	system("pause");
	return 0;
}

