#include "menu.h"
#include "text_analyzer.h"
#include "console_input.h"
#include "file_input.h"
#include "file_output.h"
#include "test.h"
#include <iostream>

void greetings() {
	std::cout << "It is the first laboratory task of the first variation. "
		"The author is Levon Abramyan, Group 404, Course 4th" << std::endl << std::endl;

	std::cout << "The problem is: " << std::endl << std::endl;

	std::cout << "Count the number of words in the given text and print them." << std::endl;
}

void print_menu() {
	std::cout << std::endl << std::endl;
	std::cout << "Enter 1 to read data from console." << std::endl;
	std::cout << "Enter 2 to read data from file." << std::endl;
	std::cout << "Enter 3 to test program." << std::endl;
	std::cout << "Enter 0 to exit." << std::endl;
}

void interface_menu() {
	bool is_restart = true;
	ConsoleInput ci;
	std::unique_ptr<Input> input;

	do {
		// constexpr FileOutput fo;
		print_menu();
		switch (const int choice = ci.get_number(static_cast<int> (EXIT), static_cast<int> (TEST)); choice) {
			case EXIT:
			std::cout << "Your choice is EXIT" << std::endl;
			is_restart = false;
			continue;
			case CONSOLE: {
				input = std::make_unique<ConsoleInput>();
			}
			break;

			case FILES: {
				input = std::make_unique<FileInput>();
			}
			break;

			case TEST: {
				const auto test = std::make_unique<Test>();
				test->start();

				if (!test->get_is_success()) {
					std::cout << "Sorry, but there is a problem test. The program will be closed." << std::endl;
					return;
				}
				continue;
			}
			default: 
			break;
		}

		auto text = std::make_unique<Text>();
		const bool is_success = input->read(*text);
		const bool is_file_input = input->get_is_file_input();
		if (is_success) {
			std::cout << std::endl << "Data read successfully!" << std::endl;
		} else {
			continue;
		}
		if (!is_file_input) {
			FileOutput::save_input_data(*text);
		}
		text->print_info();
		FileOutput::save_output_data(*text);

	} while (is_restart);
}