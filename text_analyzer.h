#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

constexpr auto LENGTH_OF_DATA = 5;

#include <vector>
#include <string>
#include <iostream>

//Класс хранящий текст, и умеющий анализировать текст
class Text {
private:
	// В этом поле хранится текст
	std::vector<std::string> data_;


	// В этом поле хранится число слов в тексте
	int number_of_words_ = 0;

	// Метод считает количество слов символов в строке
	// Записывает результат в поле @number_of_words_
	int count_number_of_words(const std::string& str);


	// Метод считает количество слов в поле @data_
	// Записывает результат в поле @number_of_words_
	void count_number_of_words();


	// Метод проверяет является ли текущий символ видимым
	bool is_visible(char c);

	// Метод проверяет является ли текущий символ буквой
	bool is_letter(char c);

	//Метод проверяет является ли текущий символ заглавной буквой
	bool is_capital_letter(char c);

public:
	[[nodiscard]] int get_number_of_words_() const;

	// В этом поле хранится текст
	std::vector<std::string> words_;

	// Конструктор для инициализации данных
	explicit Text(const std::vector<std::string>& data);


	// Конструктор по умолчанию
	Text();

	// Метод проверяет подходит ли заданная строка @line для работы с текстом
	static bool is_good_data(const std::string& line);

	// Метод печатает исходный тексте в поток @stream
	void print(std::ostream* stream = &std::cout);

	// Метод печатает слова из текста в поток @stream
	void print_words(std::ostream* stream = &std::cout);
	
	// Метод печатает информацию об исходном тексте в поток @stream
	void print_info(std::ostream* stream = &std::cout);

};

#endif