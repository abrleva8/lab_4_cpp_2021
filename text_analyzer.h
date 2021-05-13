#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

#include <vector>
#include <string>

class Text {
private:
	std::vector<std::string> data;
	int number_of_symbols = 0;
	int number_of_visible_symbols = 0;
	int number_of_words = 0;
	int number_of_lines = 0;
	int number_of_paragraphs = 0;

	void count_symbols();
	void count_visible_symbols();
	void count_number_of_words();
	void count_number_of_lines();
	void count_number_of_paragraphs();

	bool is_visible(char c);
	bool is_letter(char c);

public:
	Text(std::vector<std::string> data);
	Text();
	void print();
	void print_info();
};

#endif