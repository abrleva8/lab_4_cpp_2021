#include "file_input.h"

#include <filesystem>
#include <fstream>
#include <string>

bool FileInput::read_data_from_file(std::ifstream& file, Text& text) {
	std::vector<std::string> data;
	std::string str;
	while (!file.eof()) {
		std::getline(file, str);
		data.push_back(str);
	}
	text = Text(data);
	return true;
}

FileInput::FileInput() {
	this->is_file_input = true;
}

bool FileInput::read(Text& text) {
	std::cout << "Enter the filepath please:" << std::endl;
	std::string filepath;
	std::getline(std::cin, filepath);
	std::ifstream file(filepath);

	if (file.is_open()) {
		std::error_code ec;
		if (!std::filesystem::is_regular_file(filepath, ec)) {
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