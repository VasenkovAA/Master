
// ����������
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

// ���������� �������� ����������
#include <windows.h>
#include <conio.h>

#define MENU_SIZE 3

// �������� �����, ������� ����� ����������

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

// ���������� ������� �������
int main() {
	// ���������

	// ����� �������� ����������� ����
	system("title Application");

	// ������������� �������������� � �������� �������
	SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � ����� ������
	//setlocale(LC_ALL,"rus");
	//system("chcp 866");
	// �������� ���������� ���� �� �������� � �������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���������� ������ ������� � ������� (� ����� ���� ������ ������)
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	// ����� ����� ��� �� ���� �������
	SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	// ������� �����, ����� ��������� ����� �����������
	system("cls");

	// ���������� ����������
	int choose_pos;                    // ��������� �� ������� ���������� ������ ����
	int iKey;                          // ��������� �� �������� ������� �������
	int exit_flag;                     // ���� �� ���������� ���������
	COORD cursorPos;                   // ���������� ���������� �������, ����� ������ ��������� �����

	char* MainMenu[MENU_SIZE] = { "���������", "���������", "�����" };
	char* ListMenu[ListMenuLength] = { "MainMenu","AlgMenu","SetMenu","SortMenu","SearchMenu" };
	int ListMenuPos = 0;

	char* SortMenu[2] = { "����������� ����������", "�����" };
	char* AlgMenu[3] = { "�����", "����������", "�����" };
	char* SetMenu[3] = { "������ ������", "���������� ������� ������", "�����" };
	char* SearchMenu[3] = { "������� �����", "�������� �����", "� ���" };

	// ������������ (���������� ���������) ����������
	exit_flag = 0;
	choose_pos = 0;

	while (!exit_flag) {
		/* 1. ����� ���� � ������������� */

		// ����� ������� � ��������� ���������
		system("cls");
		iKey = 67;
		cursorPos = (COORD) { 0, 0 };
		SetConsoleCursorPosition(hStdOut, cursorPos);

		// �������� ������ ������
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

			// ������������ ������������� ����
			if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
			if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

			switch (ListMenuPos) {
			case 0:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////���������  MainMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", MainMenu[i]);
				}
				break;
			case 1:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////��������� AlgMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", AlgMenu[i]);
				}
				break;
			case 2:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////��������� SetMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", SetMenu[i]);
				}
				break;
			case 3:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////��������� SortMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", SortMenu[i]);
				}
				break;
			case 4:
				for (int i = 0; i < MENU_SIZE; i++) {                    ///////////////////////////////////////////////////////��������� SearchMenu
					cursorPos = (COORD) { 3, i };
					SetConsoleCursorPosition(hStdOut, cursorPos);
					printf("%s \n", SearchMenu[i]);
				}
				break;

			}

			// ����������� ��������� �������
			cursorPos = (COORD) { 0, choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("<<", iKey);
			cursorPos = (COORD) { strlen(MainMenu[choose_pos]) + 3 + 1, choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf(">>");

			// �������� ������ ������ �������
			iKey = _getch();
		}

		/* 2. ������� ����� ��������� */
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

	// ����� ����������
	system("cls");
	printf("Goodbay!\n");

	// ���������� ���������
	system("pause");
	return 0;
}
