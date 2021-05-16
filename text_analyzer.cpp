#include "text_analyzer.h"

#include <iostream>
#include <sstream>

Text::Text(std::vector<std::string> data) {
	this->data = data;
	this->count_symbols();
	this->count_visible_symbols();
	this->count_number_of_words();
	this->count_number_of_lines();
	this->count_number_of_paragraphs();
	this->set_sentences();
	this->set_data_sentences();
}

Text::Text() {
}

void Text::count_number_of_lines() {
	this->number_of_lines = data.size();
}

bool Text::is_end_symbol(char c) {
	return c == '.' || c == '!' || c == '?';
}

bool Text::is_visible(char c) {
	return '!' <= c && c <= '~';
}

bool Text::is_letter(char c) {
	return 'a' <= c && c <= 'z' || is_capital_letter(c);
}

bool Text::is_capital_letter(char c) {
	return 'A' <= c && c <= 'Z';
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

int Text::count_number_of_words(std::string str) {
	int result = 0;
	bool is_new_word = false;
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

	return result;
}

void Text::count_number_of_words() {
	int result = 0;
	for (auto str : this->data) {
		result += count_number_of_words(str);
	}
	this->number_of_words = result;
}

void Text::print(std::ostream* stream) {
	size_t size = data.size();
	for (size_t i = 0; i < data.size(); i++) {
		*stream << data[i];
		if (i != size - 1) {
			*stream << std::endl;
		}
	}
}

void Text::print_info(std::ostream* stream) {
	*stream << "The numbers of symbols in the text equals " << this->number_of_symbols << std::endl;
	*stream << "The numbers of visible symbols in the text equals " << this->number_of_visible_symbols << std::endl;
	*stream << "The numbers of words in the text equals " << this->number_of_words << std::endl;
	*stream << "The numbers of lines in the text equals " << this->number_of_lines << std::endl;
	*stream << "The numbers of paragraphs in the text equals " << this->number_of_paragraphs;
	if (stream->rdbuf() == std::cout.rdbuf()) {
		*stream << std::endl;
	}
}

void Text::print_sentences(std::ostream* stream) {
	for (auto str : this->sentences) {
		std::cout << str << std::endl;
	}
}

void Text::print_sentences_info(std::ostream* stream) {
	for (std::map<int, int>::iterator it = sentence_data.begin(); it != sentence_data.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

void Text::count_number_of_paragraphs() {
	int result = 0;
	char tab = '\t';
	for (auto str : data) {
		bool is_last_tab = false;
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

void Text::set_sentences() {
	
	std::stringstream ss;
	for (auto str : this->data) {
		int start_sentence = -1;
		int end_sentence = -1;
		for (int i = 0; i < str.length(); i++) {
			if (is_capital_letter(str[i]) && end_sentence == -1) {
				start_sentence = i;
				end_sentence = i;
			}

			if (end_sentence != -1) {
				end_sentence++;
				ss << str[i];
			}

			if (is_end_symbol(str[i]) && start_sentence != -1) {
				this->sentences.push_back(ss.str());
				ss.str("");
				start_sentence = -1;
				end_sentence = -1;
			}
		}
	}
}

void Text::set_data_sentences() {
	for (auto str : sentences) {
		int number = count_number_of_words(str);
		if (sentence_data.find(number) == sentence_data.end()) {
			sentence_data.insert(std::pair<int, int>(number, 1));
		} else {
			sentence_data[number]++;
		}
	}
}