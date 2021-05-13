#ifndef _MENU_H_
#define _MENU_H_

// Перечисление которое хранит пункты базового меню
enum MENU {
	EXIT,
	CONSOLE,
	FILES,
	TEST
};

// Приветствие пользователя
void greetings();

// Печает пунты меню
void print_menu();

// На данный момент реализована логика меню программы
void interface_menu();

#endif
