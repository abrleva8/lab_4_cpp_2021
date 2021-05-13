#ifndef _INPUT_H_
#define _INPUT_H_

#include "text_analyzer.h"

// ����������� ����� ����������� ������ �������
class Input {
protected:
	bool is_file_input;
public:
	// �������� ������:
	// 1 - �������� � ���� @matrix - �������
	// 2 - ������� ������� ��� ���
	virtual bool read(Text &text) = 0;

	bool get_is_file_input();

	// ����������� ����������
	virtual ~Input() = default;
};

#endif