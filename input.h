#ifndef _INPUT_H_
#define _INPUT_H_

#include "text_analyzer.h"

// Абстрактный класс реализующий чтение массива
class Input {
protected:
	bool is_file_input;
public:
	// Контракт метода:
	// 1 - Записать в поле @matrix - матрицу
	// 2 - Вернуть успешно или нет
	virtual bool read(Text &text) = 0;

	bool get_is_file_input();

	// Виртуальный деструктор
	virtual ~Input() = default;
};

#endif