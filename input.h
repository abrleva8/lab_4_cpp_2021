#ifndef _INPUT_H_
#define _INPUT_H_

#include "text_analyzer.h"

// Абстрактный класс реализующий чтение массива
class Input {
public:
	// Контракт метода:
	// 1 - Записать в поле @matrix - матрицу
	// 2 - Вернуть успешно или нет
	virtual bool read(Text &text) = 0;

	// Виртуальный деструктор
	virtual ~Input() = default;
};

#endif