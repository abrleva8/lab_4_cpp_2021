#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

#include <vector>
#include <map>
#include <string>
#include <iostream>

class Text {
private:
	std::vector<std::string> data;
	std::vector<std::string> sentences;
	std::map<int, int> sentence_data;
	int number_of_symbols = 0;
	int number_of_visible_symbols = 0;
	int number_of_words = 0;
	int number_of_lines = 0;
	int number_of_paragraphs = 0;

	void count_symbols();
	void count_visible_symbols();
	int count_number_of_words(std::string str);
	void count_number_of_words();
	void count_number_of_lines();
	void count_number_of_paragraphs();

	void set_sentences();
	void set_data_sentences();

	bool is_end_symbol(char c);
	bool is_visible(char c);
	bool is_letter(char c);
	bool is_capital_letter(char c);

public:
	Text(std::vector<std::string> data);
	Text();
	void print(std::ostream* stream = &std::cout);
	void print_info(std::ostream* stream = &std::cout);
	void print_sentences(std::ostream* stream = &std::cout);
	void print_sentences_info(std::ostream* stream = &std::cout);
};

#endif