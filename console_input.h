#ifndef _CONSOLE_INPUT_H_
#define _CONSOLE_INPUT_H_

#include "input.h"

#include <iostream>

// Класс для работы с консольный вводом
class ConsoleInput final : public Input {
private:
	const std::string end_ = "end";
public:

	ConsoleInput();
	// Реализация метода из класса @Input
	bool read(Text& text) override;

	// Спрашивает у пользователя "да" или "нет"
	// Если введено 'y' -  возвращает @true
	// Если введено 'n' -  возвращает @false
	static bool is_choice_yes();

	// Шаблонный метод который возвращает число
	// Работает с базовыми типами данных
	template<class Type>
	Type get_number();

	// Шаблонный метод который возвращает число c промежутка [@min; @max]
	// Работает с базовыми типами данных
	template<class Type>
	Type get_number(Type min, Type max);
};

template<typename Type>
Type ConsoleInput::get_number() {
	Type input;
	std::cin >> input;

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Wrong input, try again." << std::endl;
		std::cin >> input;
	}

	std::cin.ignore(INT_MAX, '\n');

	return input;
}

template<typename Type>
Type ConsoleInput::get_number(Type min, Type max) {
	Type result = get_number<Type>();
	while (result > max || result < min) {
		std::cout << "Your number should be between " << min << " and " << max << std::endl;
		std::cout << "Try again, please!" << std::endl;
		result = get_number<Type>();
	}
	return result;
}
#endif