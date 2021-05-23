#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

#define LENGTH_OF_DATA 5

#include <vector>
#include <map>
#include <string>
#include <iostream>

//Класс хранящий текст, и умеющий анализировать текст
class Text {
private:
	// В этом поле хранится текст
	std::vector<std::string> data_;

	// В этом поле поле хранятся предложения текста
	std::vector<std::string> sentences_;

	// В этом поле хранится информация(количество слов) о предложениях
	std::map<int, int> sentence_data_;

	// В этом поле хранится число символов в тексте
	int number_of_symbols_ = 0;

	// В этом поле хранится число видимых символов в тексте
	int number_of_visible_symbols_ = 0;
	
	// В этом поле хранится число слов в тексте
	int number_of_words_ = 0;

	// В этом поле хранится число строк в тексте
	int number_of_lines_ = 0;

	// В этом поле хранится число абзацев в тексте
	int number_of_paragraphs_ = 0;

	// Метод считает количество символов в поле @data_
	// Записывает результат в поле @number_of_symbols_
	void count_symbols();

	// Метод считает количество видимых символов в поле @data_
	// Записывает результат в поле @number_of_visible_symbols_
	void count_visible_symbols();

	// Метод считает количество слов символов в строке
	// Записывает результат в поле @number_of_words_
	static int count_number_of_words(std::string str);

	// Метод считает количество слов в поле @data_
	// Записывает результат в поле @number_of_words_
	void count_number_of_words();

	// Метод считает количество строк в поле @data_
	// Записывает результат в поле @number_of_words_
	void count_number_of_lines();

	// Метод считает количество абзацев в поле @data_
	// Записывает результат в поле @number_of_words_
	void count_number_of_paragraphs();

	// Метод ищет предложения в поле @data_
	// Записывает результат в поле @sentences_
	void set_sentences();

	// Метод количество в каждом предложении в поле @sentences_
	// Хранит количество слов в предложении и их количество
	// Записывает результат в поле @data_sentences_
	void set_data_sentences();

	// Метод проверяет является ли текущий символ концом строки
	static bool is_end_symbol(char c);

	// Метод проверяет является ли текущий символ видимым
	static bool is_visible(char c);

	// Метод проверяет является ли текущий символ буквой
	static bool is_letter(char c);

	// Метод проверяет есть ли в тексте предложения
	[[nodiscard]] bool has_sentence() const;

	//Метод проверяет является ли текущий символ заглавной буквой
	static bool is_capital_letter(char c);

public:
	// Конструктор для инициализации данных
	explicit Text(const std::vector<std::string>& data);

	// Конструктор по умолчанию
	Text();

	// Метод проверяет подходит ли заданная строка @line для работы с текстом
	static bool is_good_data(const std::string& line);

	// Метод печатает исходный тексте в поток @stream
	void print(std::ostream* stream = &std::cout);
	
	// Метод печатает информацию об исходном тексте в поток @stream
	void print_info(std::ostream* stream = &std::cout) const;

	// Метод печатает информацию об предложениях исходного текста в поток @stream
	void print_sentences_info(std::ostream* stream = &std::cout);

	// Метод возвращает массив данных о тексте
	// !!!Нужна только для тестирования!!!
	[[nodiscard]] std::unique_ptr<int[]> get_info() const;
};

#endif