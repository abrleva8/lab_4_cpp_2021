#include "text_analyzer.h"

#include <algorithm>
#include <iostream>
#include <sstream>

int Text::get_number_of_words_() const {
	return this->number_of_words_;
}

Text::Text(const std::vector<std::string>& data) {
	this->data_ = data;
	this->count_number_of_words();
}

Text::Text() = default;

auto is_good_symbol{
  [](const char c) {
	return '~' >= c && c >= ' ' || c == '\t';
  }
};

bool Text::is_good_data(const std::string& line) {
	return std::all_of(line.begin(), line.end(), is_good_symbol);
}

bool Text::is_letter(const char c) {
	return 'a' <= c && c <= 'z' || is_capital_letter(c);
}

bool Text::is_capital_letter(const char c) {
	return 'A' <= c && c <= 'Z';
}

int Text::count_number_of_words(const std::string& str) {
	int result = 0;
	bool is_new_word = false;
	int start_index = -1;
	int end_index = -1;
	for (int i = 0; i < str.size(); i++) {
		if (is_letter(str[i])) {
			if (!is_new_word) {
				start_index = i;
			}
			is_new_word = true;
			end_index = i;
			if (i == str.size() - 1) {
				result++;
				words_.emplace_back(str.substr(start_index, end_index - start_index + 1));
			}
		} else {
			if (is_new_word) {
				result++;
				words_.emplace_back(str.substr(start_index, end_index - start_index + 1));
				is_new_word = false;
				start_index = i;
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
	const size_t size = data_.size();
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

void Text::print_words(std::ostream* stream) {
	*stream << "Words:" << std::endl;
	for (auto element : words_) {
		*stream << element << std::endl;
	}

	*stream << std::endl;
}

void Text::print_info(std::ostream* stream) {
	*stream << "The numbers of words in the text equals " << this->number_of_words_ << std::endl;
	print_words(stream);
	if (stream->rdbuf() == std::cout.rdbuf()) {
		*stream << std::endl;
	}
}