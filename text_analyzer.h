#ifndef _TEXT_ANALYZER_H_
#define TEXT_ANALYZER_H

#include <vector>
#include <map>
#include <string>
#include <iostream>

class Text {
private:
	std::vector<std::string> data_;
	std::vector<std::string> sentences_;
	std::map<int, int> sentence_data_;
	int number_of_symbols_ = 0;
	int number_of_visible_symbols_ = 0;
	int number_of_words_ = 0;
	int number_of_lines_ = 0;
	int number_of_paragraphs_ = 0;

	void count_symbols();
	void count_visible_symbols();
	int count_number_of_words(std::string str);
	void count_number_of_words();
	void count_number_of_lines();
	void count_number_of_paragraphs();

	void set_sentences();
	void set_data_sentences();

	static bool is_end_symbol(char c);
	static bool is_visible(char c);
	bool is_letter(char c);
	static bool is_capital_letter(char c);

public:
	explicit Text(std::vector<std::string> data);
	Text();
	void print(std::ostream* stream = &std::cout);
	void print_info(std::ostream* stream = &std::cout);
	void print_sentences(std::ostream* stream = &std::cout);
	void print_sentences_info(std::ostream* stream = &std::cout);
};

#endif