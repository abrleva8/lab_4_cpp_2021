#ifndef _CONSOLE_INPUT_H_
#define _CONSOLE_INPUT_H_

#include "input.h"

#include <iostream>

// ����� ��� ������ � ���������� ������
class ConsoleInput final : public Input {
private:
	const std::string end_ = "end";
public:

	ConsoleInput();
	// ���������� ������ �� ������ @Input
	bool read(Text& text) override;

	// ���������� � ������������ "��" ��� "���"
	// ���� ������� 'y' -  ���������� @true
	// ���� ������� 'n' -  ���������� @false
	static bool is_choice_yes();

	// ��������� ����� ������� ���������� �����
	// �������� � �������� ������ ������
	template<class Type>
	Type get_number();

	// ��������� ����� ������� ���������� ����� c ���������� [@min; @max]
	// �������� � �������� ������ ������
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