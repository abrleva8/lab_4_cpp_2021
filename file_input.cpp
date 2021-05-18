#include "file_input.h"

#include <filesystem>
#include <fstream>
#include <string>

bool FileInput::read_data_from_file(std::ifstream& file, Text& text) const {
	std::vector<std::string> data;
	while (!file.eof()) {
		std::string str;
		std::getline(file, str);
		if (!Text::is_good_data(str)) {
			std::cerr << "The file has unreadable symbols!";
			return false;
		}
		data.push_back(str);
	}
	text = Text(data);
	return true;
}

FileInput::FileInput() {
	this->is_file_input_ = true;
}

bool FileInput::read(Text& text) {
	std::cout << "Enter the filepath please:" << std::endl;
	std::string filepath;
	std::getline(std::cin, filepath);

	if (std::ifstream file(filepath); file.is_open()) {
		if (std::error_code ec; !std::filesystem::is_regular_file(filepath, ec)) {
			std::cerr << "Sorry, there is a problem with file." << std::endl;
			file.close();
			return false;
		}
		return read_data_from_file(file, text);
	} else {
		std::cerr << "Sorry, the file can't be opened." << std::endl;
		file.close();
		return false;
	}
}