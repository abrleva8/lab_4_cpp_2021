#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

#define LENGTH_OF_DATA 5

#include <vector>
#include <map>
#include <string>
#include <iostream>

//����� �������� �����, � ������� ������������� �����
class Text {
private:
	// � ���� ���� �������� �����
	std::vector<std::string> data_;

	// � ���� ���� ���� �������� ����������� ������
	std::vector<std::string> sentences_;

	// � ���� ���� �������� ����������(���������� ����) � ������������
	std::map<int, int> sentence_data_;

	// � ���� ���� �������� ����� �������� � ������
	int number_of_symbols_ = 0;

	// � ���� ���� �������� ����� ������� �������� � ������
	int number_of_visible_symbols_ = 0;
	
	// � ���� ���� �������� ����� ���� � ������
	int number_of_words_ = 0;

	// � ���� ���� �������� ����� ����� � ������
	int number_of_lines_ = 0;

	// � ���� ���� �������� ����� ������� � ������
	int number_of_paragraphs_ = 0;

	// ����� ������� ���������� �������� � ���� @data_
	// ���������� ��������� � ���� @number_of_symbols_
	void count_symbols();

	// ����� ������� ���������� ������� �������� � ���� @data_
	// ���������� ��������� � ���� @number_of_visible_symbols_
	void count_visible_symbols();

	// ����� ������� ���������� ���� �������� � ������
	// ���������� ��������� � ���� @number_of_words_
	static int count_number_of_words(std::string str);

	// ����� ������� ���������� ���� � ���� @data_
	// ���������� ��������� � ���� @number_of_words_
	void count_number_of_words();

	// ����� ������� ���������� ����� � ���� @data_
	// ���������� ��������� � ���� @number_of_words_
	void count_number_of_lines();

	// ����� ������� ���������� ������� � ���� @data_
	// ���������� ��������� � ���� @number_of_words_
	void count_number_of_paragraphs();

	// ����� ���� ����������� � ���� @data_
	// ���������� ��������� � ���� @sentences_
	void set_sentences();

	// ����� ���������� � ������ ����������� � ���� @sentences_
	// ������ ���������� ���� � ����������� � �� ����������
	// ���������� ��������� � ���� @data_sentences_
	void set_data_sentences();

	// ����� ��������� �������� �� ������� ������ ������ ������
	static bool is_end_symbol(char c);

	// ����� ��������� �������� �� ������� ������ �������
	static bool is_visible(char c);

	// ����� ��������� �������� �� ������� ������ ������
	static bool is_letter(char c);

	// ����� ��������� ���� �� � ������ �����������
	[[nodiscard]] bool has_sentence() const;

	//����� ��������� �������� �� ������� ������ ��������� ������
	static bool is_capital_letter(char c);

public:
	// ����������� ��� ������������� ������
	explicit Text(const std::vector<std::string>& data);

	// ����������� �� ���������
	Text();

	// ����� ��������� �������� �� �������� ������ @line ��� ������ � �������
	static bool is_good_data(const std::string& line);

	// ����� �������� �������� ������ � ����� @stream
	void print(std::ostream* stream = &std::cout);
	
	// ����� �������� ���������� �� �������� ������ � ����� @stream
	void print_info(std::ostream* stream = &std::cout) const;

	// ����� �������� ���������� �� ������������ ��������� ������ � ����� @stream
	void print_sentences_info(std::ostream* stream = &std::cout);

	// ����� ���������� ������ ������ � ������
	// !!!����� ������ ��� ������������!!!
	[[nodiscard]] std::unique_ptr<int[]> get_info() const;
};

#endif