#ifndef _TEST_H_
#define _TEST_H_

#define NUMBER_OF_TESTS 5

#include "text_analyzer.h"


class Test {
private:
	Text data_[NUMBER_OF_TESTS];
	int answers_[NUMBER_OF_TESTS][5];
	bool is_success_;
	int check_in();
public:
	Test();
	void start();
	[[nodiscard]] bool get_is_success() const;
};

#endif