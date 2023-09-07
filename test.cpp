#include "test.h"
#include "vector"

Test::Test() {
	std::vector<std::string> text;
	text.emplace_back("\tAmy normally hated Monday mornings, but this year was different.");
	text.emplace_back("\tKamal was in her art class and she liked Kamal.");
	text.emplace_back("\tShe was waiting outside the classroom when her friend Tara arrived.");
	data_[0] = Text(text);

	answers_[0] = 31;

	text.clear();
	text.emplace_back("\tHi Amy!");
	text.emplace_back("\tYour mum sent me a text.");
	text.emplace_back("\tYou forgot your inhaler.");
	data_[1] = Text(text);
	answers_[1] = 12;

	text.clear();
	data_[2] = Text(text);
	answers_[2] = 0;

	text.clear();
	text.emplace_back("\tDid Kamal ask you to the disco?");
	text.emplace_back("Tara was Amy’s best friend, and she wanted to know everything that was happening in Amy’s life.");
	data_[3] = Text(text);
	answers_[3] = 26;


	text.clear();
	text.emplace_back("\t\t\t");
	text.emplace_back("\t\t\t");
	data_[4] = Text(text);
	answers_[4] = 0;
}

int Test::check_in() {

	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		if (const int ans = this->data_[i].get_number_of_words_(); ans != answers_[i]) {
			std::cout << "Right answer = " << answers_[i] << std::endl;
			std::cout << "Your answer = " << ans << std::endl;
			return i;
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