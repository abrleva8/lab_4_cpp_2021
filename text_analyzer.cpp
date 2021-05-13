#include "text_analyzer.h"

#include <iostream>

Text::Text(std::vector<std::string> data) {
	this->data = data;
	this->count_symbols();
	this->count_visible_symbols();
	this->count_number_of_words();
	this->count_number_of_lines();
	this->count_number_of_paragraphs();
}

Text::Text() {
}

void Text::count_number_of_lines() {
	this->number_of_lines = data.size();
}

bool Text::is_visible(char c) {
	return '!' <= c && c <= '~';
}

bool Text::is_letter(char c) {
	return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}

void Text::count_symbols() {
	int result = 0;
	for (auto str : this->data) {
		result += str.size();
	}
	this->number_of_symbols = result;
}

void Text::count_visible_symbols() {
	int result = 0;
	for (auto str : this->data) {
		for (auto ch : str) {
			if (is_visible(ch)) {
				result++;
			}
		}
	}
	this->number_of_visible_symbols = result;
}

void Text::count_number_of_words() {
	int result = 0;
	bool is_new_word = false;
	for (auto str : this->data) {
		for (int i = 0; i < str.size(); i++) {
			if (is_letter(str[i])) {
				if (i == str.size() - 1) {
					result++;
				}
				is_new_word = true;
			} else {
				if (is_new_word) {
					result++;
					is_new_word = false;
				}
			}
		}
	}
	this->number_of_words = result;
}

void Text::print() {
	for (auto str : data) {
		std::cout << str << std::endl;
	}
}

void Text::print_info() {
	std::cout << "The numbers of symbols in the text equals " << this->number_of_symbols << std::endl;
	std::cout << "The numbers of visible symbols in the text equals " << this->number_of_visible_symbols << std::endl;
	std::cout << "The numbers of words in the text equals " << this->number_of_words << std::endl;
	std::cout << "The numbers of lines in the text equals " << this->number_of_lines << std::endl;
	std::cout << "The numbers of paragraphs in the text equals " << this->number_of_paragraphs << std::endl;
}

void Text::count_number_of_paragraphs() {
	int result = 0;
	char tab = '\t';
	bool is_last_tab = false;
	for (auto str : data) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == tab) {
				if (!is_last_tab) {
					result++;
					is_last_tab = true;
			}
			} else {
				is_last_tab = false;
			}
		}
	}
	this->number_of_paragraphs = result;
}
