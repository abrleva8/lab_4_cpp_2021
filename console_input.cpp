#include "console_input.h"

#include <iostream>
#include <string>

ConsoleInput::ConsoleInput() {
	this->is_file_input_ = false;
}

bool ConsoleInput::read(Text& text) {
	std::vector<std::string> data;
	std::string str;
	std::cout << "Enter \"end\" to finish input." << std::endl;
	getline(std::cin, str);
	while (str != end_) {
		if (!Text::is_good_data(str)) {
			std::cerr << "The previous line has bad symbols! Please, try input English letters" << std::endl;
		} else {
			data.push_back(str);
		}
		getline(std::cin, str);
	}
	text = Text(data);
	return true;
}

bool ConsoleInput::is_choice_yes() {
	std::string save{};
	std::getline(std::cin, save);
	while (save != "y" && save != "n") {
		std::cout << "Wrong input. Please input y/n" << std::endl;
		std::getline(std::cin, save);
	}
	return save != "n";
}