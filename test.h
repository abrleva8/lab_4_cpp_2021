#ifndef _TEST_H_
#define _TEST_H_

#define NUMBER_OF_TESTS 5

#include "text_analyzer.h"


//����� ����������� ������ ������������
class Test {
private:
	//� ���� ���� �������� ������ ��� �����
	Text data_[NUMBER_OF_TESTS];

	//� ���� ���� �������� ������ �� �����
	int answers_[NUMBER_OF_TESTS];

	//� ���� ���� �������� ������� �� ������ ������������
	bool is_success_;

	//����� ��������� ������ ������ ���  @data_ � ������� � @answers_
	// ���������� ���� � ������� ������
	// ���� ������  ���, �� -1
	int check_in();
public:
	// ����������� ��� ������������� �����
	Test();

	// ����� ����������� ��������� ������������
	void start();

	// ����� ���������� ���������, ������� �������� � ���� is_success_
	[[nodiscard]] bool get_is_success() const;
};

#endif