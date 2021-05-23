#ifndef _TEST_H_
#define _TEST_H_

#define NUMBER_OF_TESTS 5

#include "text_analyzer.h"


//Класс реализующий модуль тестирования
class Test {
private:
	//В этом поле хранятся данные для теста
	Text data_[NUMBER_OF_TESTS];

	//В этом поле хранятся ответы на тесты
	int answers_[NUMBER_OF_TESTS][LENGTH_OF_DATA];

	//В этом поле хранится успешно ли прошло тестирование
	bool is_success_;

	//Метод запускает анализ текста для  @data_ и сверяет с @answers_
	// Возвращает тест с номером ошибки
	// Если ошибки  нет, то -1
	int check_in();
public:
	// Конструктор для инициализации полей
	Test();

	// Метод запускающий процедуру тестирования
	void start();

	// Метод возвращает результат, который хранится в поле is_success_
	[[nodiscard]] bool get_is_success() const;
};

#endif