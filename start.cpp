#include <iostream>
#include <cstdlib>
#include "menu.h"

// ����� ���������
int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	greetings();
	interface_menu();
	system("pause");
}