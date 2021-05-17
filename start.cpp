#include <iostream>
#include <cstdlib>
#include "menu.h"

// Старт программы
int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	greetings();
	interface_menu();
	system("pause");
}