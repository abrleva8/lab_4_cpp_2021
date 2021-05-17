#include "text_analyzer.h"

#include <iostream>
#include <sstream>

Text::Text(std::vector<std::string> data) {
	this->data_ = data;
	this->count_number_of_lines();
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
	this->number_of_lines_ = data_.size();
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
	for (const auto& str : this->data_) {
		result += str.size();
	}
	result += this->number_of_lines_;
	this->number_of_symbols_ = result;
}

void Text::count_visible_symbols() {
	int result = 0;
	for (const auto& str : this->data_) {
		for (auto ch : str) {
			if (is_visible(ch)) {
				result++;
			}
		}
	}
	this->number_of_visible_symbols_ = result;
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
	for (const auto& str : this->data_) {
		result += count_number_of_words(str);
	}
	this->number_of_words_ = result;
}

void Text::print(std::ostream* stream) {
	size_t size = data_.size();
	for (size_t i = 0; i < data_.size(); i++) {
		*stream << data_[i];
		if (i != size - 1) {
			*stream << std::endl;
		} else {
			if (stream->rdbuf() == std::cout.rdbuf()) {
				*stream << std::endl;
			}
		}


	}
}

void Text::print_info(std::ostream* stream) {
	*stream << "The numbers of symbols in the text equals " << this->number_of_symbols_ << std::endl;
	*stream << "The numbers of visible symbols in the text equals " << this->number_of_visible_symbols_ << std::endl;
	*stream << "The numbers of words in the text equals " << this->number_of_words_ << std::endl;
	*stream << "The numbers of lines in the text equals " << this->number_of_lines_ << std::endl;
	*stream << "The numbers of paragraphs in the text equals " << this->number_of_paragraphs_;
	if (stream->rdbuf() == std::cout.rdbuf()) {
		*stream << std::endl;
	}
}

void Text::print_sentences(std::ostream* stream) {
	for (const auto& str : this->sentences_) {
		std::cout << str << std::endl;
	}
}

void Text::print_sentences_info(std::ostream* stream) {
	for (auto it = sentence_data_.begin(); it != sentence_data_.end(); ++it)
		*stream << it->first << " => " << it->second << std::endl;
}

void Text::count_number_of_paragraphs() {
	int result = 0;
	for (const auto& str : data_) {
		bool is_last_tab = false;
		for (char i : str) {
			if (const char tab = '\t'; i == tab) {
				if (!is_last_tab) {
					result++;
					is_last_tab = true;
				}
			} else {
				is_last_tab = false;
			}
		}
	}
	this->number_of_paragraphs_ = result;
}

void Text::set_sentences() {
	
	std::stringstream ss;
	for (auto str : this->data_) {
		size_t start_sentence = -1;
		size_t end_sentence = -1;
		for (size_t i = 0; i < str.length(); i++) {
			if (is_capital_letter(str[i]) && end_sentence == -1) {
				start_sentence = i;
				end_sentence = i;
			}

			if (end_sentence != -1) {
				end_sentence++;
				ss << str[i];
			}

			if (is_end_symbol(str[i]) && start_sentence != -1) {
				this->sentences_.push_back(ss.str());
				ss.str("");
				start_sentence = -1;
				end_sentence = -1;
			}
		}
	}
}

void Text::set_data_sentences() {
	for (const auto& str : sentences_) {
		if (int number = count_number_of_words(str); sentence_data_.find(number) == sentence_data_.end()) {
			sentence_data_.insert(std::pair<int, int>(number, 1));
		} else {
			sentence_data_[number]++;
		}
	}
}