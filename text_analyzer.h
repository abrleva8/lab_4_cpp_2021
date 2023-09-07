#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

constexpr auto LENGTH_OF_DATA = 5;

#include <vector>
#include <string>
#include <iostream>

//����� �������� �����, � ������� ������������� �����
class Text {
private:
	// � ���� ���� �������� �����
	std::vector<std::string> data_;


	// � ���� ���� �������� ����� ���� � ������
	int number_of_words_ = 0;

	// ����� ������� ���������� ���� �������� � ������
	// ���������� ��������� � ���� @number_of_words_
	int count_number_of_words(const std::string& str);


	// ����� ������� ���������� ���� � ���� @data_
	// ���������� ��������� � ���� @number_of_words_
	void count_number_of_words();


	// ����� ��������� �������� �� ������� ������ �������
	bool is_visible(char c);

	// ����� ��������� �������� �� ������� ������ ������
	bool is_letter(char c);

	//����� ��������� �������� �� ������� ������ ��������� ������
	bool is_capital_letter(char c);

public:
	[[nodiscard]] int get_number_of_words_() const;

	// � ���� ���� �������� �����
	std::vector<std::string> words_;

	// ����������� ��� ������������� ������
	explicit Text(const std::vector<std::string>& data);


	// ����������� �� ���������
	Text();

	// ����� ��������� �������� �� �������� ������ @line ��� ������ � �������
	static bool is_good_data(const std::string& line);

	// ����� �������� �������� ������ � ����� @stream
	void print(std::ostream* stream = &std::cout);

	// ����� �������� ����� �� ������ � ����� @stream
	void print_words(std::ostream* stream = &std::cout);
	
	// ����� �������� ���������� �� �������� ������ � ����� @stream
	void print_info(std::ostream* stream = &std::cout);

};

#endif