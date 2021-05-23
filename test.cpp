#include "test.h"
#include "vector"

Test::Test() {
	std::vector<std::string> text;
	text.emplace_back("\tAmy normally hated Monday mornings, but this year was different.");
	text.emplace_back("\tKamal was in her art class and she liked Kamal.");
	text.emplace_back("\tShe was waiting outside the classroom when her friend Tara arrived.");
	data_[0] = Text(text);
	answers_[0][0] = 184;
	answers_[0][1] = 150;
	answers_[0][2] = 31;
	answers_[0][3] = 3;
	answers_[0][4] = 3;

	text.clear();
	text.emplace_back("\tHi Amy!");
	text.emplace_back("\tYour mum sent me a text.");
	text.emplace_back("\tYou forgot your inhaler.");
	data_[1] = Text(text);
	answers_[1][0] = 61;
	answers_[1][1] = 46;
	answers_[1][2] = 12;
	answers_[1][3] = 3;
	answers_[1][4] = 3;

	text.clear();
	data_[2] = Text(text);
	answers_[2][0] = 0;
	answers_[2][1] = 0;
	answers_[2][2] = 0;
	answers_[2][3] = 0;
	answers_[2][4] = 0;

	text.clear();
	text.emplace_back("\tDid Kamal ask you to the disco?");
	text.emplace_back("Tara was Amy’s best friend, and she wanted to know everything that was happening in Amy’s life.");
	data_[3] = Text(text);
	answers_[3][0] = 129;
	answers_[3][1] = 102;
	answers_[3][2] = 26;
	answers_[3][3] = 2;
	answers_[3][4] = 1;

	text.clear();
	text.emplace_back("\t\t\t");
	text.emplace_back("\t\t\t");
	data_[4] = Text(text);
	answers_[4][0] = 8;
	answers_[4][1] = 0;
	answers_[4][2] = 0;
	answers_[4][3] = 2;
	answers_[4][4] = 2;
}

int Test::check_in() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		for (int j = 0; j < LENGTH_OF_DATA; j++) {
			if (std::unique_ptr<int[]> ans = this->data_[i].get_info(); ans[j] != answers_[i][j]) {
				std::cout << "The parameter with number " << j << " is wrong." << std::endl;
				std::cout << "Right answer = " << answers_[i][j] << std::endl;
				std::cout << "Your answer = " << ans[j] << std::endl;
				return i;
			}
		}
	}
	//delete[] this->answers_;
	return -1;
}

bool Test::get_is_success() const {
	return this->is_success_;
}

void Test::start() {
	if (const int result = check_in(); result == -1) {
		std::cout << "The testing has passed successfully!" << std::endl;
	} else {
		std::cout << "The program was failed in the test with number " << result + 1 << std::endl;
		is_success_ = false;
	}
	std::cout << std::endl;
}