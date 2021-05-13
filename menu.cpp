#include "menu.h"
#include "text_analyzer.h"
#include "console_input.h"
#include <iostream>

void greetings() {
	std::cout << "It is the fourth laboratory task of the first variation. "
		"The author is Levon Abramyan, Group 404, Course 1st" << std::endl << std::endl;

	std::cout << "The problem is: " << std::endl << std::endl;

	std::cout <<"Count the number of characters, words, lines, paragraphs in the given text." << std::endl <<
				"Calculate the number of words in sentences and display a statistical table in which" << std::endl <<
				"the length of a sentence in words will correspond to the number of such sentences in the analyzed text."
	<< std::endl << std::endl;
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

	do {
		print_menu();
		int choice = ci.get_number(static_cast<int> (EXIT), static_cast<int> (TEST));
		switch (choice) {
			case EXIT:
			std::cout << "Your choice is EXIT" << std::endl;
			is_restart = false;
			continue;
			break;

			case CONSOLE:{
				Text *text = new Text();
				ci.read(*text);
				text->print();
				text->print_info();
			}
			break;

			case FILES:{
				
			}
			break;

			case TEST:{
			}
			break;
		}

	} while (is_restart);
}
