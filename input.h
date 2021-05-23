#ifndef _INPUT_H_
#define _INPUT_H_

#include "text_analyzer.h"

// ����������� ����� ����������� ������ �������
class Input {
protected:
	bool is_file_input_ = false;
public:
	// �������� ������:
	// 1 - �������� � ���� @text - �����
	// 2 - ������� ������� ��� ���
	virtual bool read(Text& text) = 0;

	[[nodiscard]] bool get_is_file_input() const;

	// ����������� ����������
	virtual ~Input() = default;
};

#endif