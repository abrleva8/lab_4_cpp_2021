#ifndef _FILE_INPUT_H_
#define _FILE_INPUT_H_

#include <iostream>

#include "input.h"
#include "text_analyzer.h"

// Класс, реализующий чтение из файла текста
class FileInput final : public Input {
private:

	// Процесс чтения из файла, на корректном файле
	bool read_data_from_file(std::ifstream& file, Text& text) const;

public:
	FileInput();
	// Реализация метода класса @Input
	bool read(Text& text) override;

};

#endif