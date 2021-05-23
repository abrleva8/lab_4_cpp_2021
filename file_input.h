#ifndef _FILE_INPUT_H_
#define _FILE_INPUT_H_

#include <iostream>

#include "input.h"
#include "text_analyzer.h"

// �����, ����������� ������ �� ����� ������
class FileInput final : public Input {
private:

	// ������� ������ �� �����, �� ���������� �����
	bool read_data_from_file(std::ifstream& file, Text& text) const;

public:
	FileInput();
	// ���������� ������ ������ @Input
	bool read(Text& text) override;

};

#endif