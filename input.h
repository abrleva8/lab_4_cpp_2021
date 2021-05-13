#ifndef _INPUT_H_
#define _INPUT_H_

#include "text_analyzer.h"

// ����������� ����� ����������� ������ �������
class Input {
public:
	// �������� ������:
	// 1 - �������� � ���� @matrix - �������
	// 2 - ������� ������� ��� ���
	virtual bool read(Text &text) = 0;

	// ����������� ����������
	virtual ~Input() = default;
};

#endif