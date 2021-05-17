#include "console_input.h"

#include <iostream>
#include <string>

ConsoleInput::ConsoleInput() {
	this->is_file_input = false;
}

bool ConsoleInput::read(Text &text) {
	std::vector<std::string> data;
	std::string str;
	std::cout << "Enter \"end\" to finish input." << std::endl;
	getline(std::cin, str);
	while (str != END) {
		data.push_back(str);
		getline(std::cin, str);
	}
	text = Text(data);
	return true;
}

bool ConsoleInput::is_choice_yes() const {
	std::string save;
	std::getline(std::cin, save);
	while (save == "y" && save != "n") {
		std::cout << "Wrong input. Please input y/n" << std::endl;
		std::getline(std::cin, save);
	}
	return save == "n";
}
