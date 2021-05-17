#include "file_output.h"
#include "console_input.h"

#include <iostream>
#include <fstream>
#include <filesystem>

void FileOutput::try_overwrite_file(std::string& filename) {
	std::error_code ec;
	if (!std::filesystem::is_regular_file(filename, ec)) {
		return;
	}
	bool is_overwrite = false;

	while (is_file_exist(filename) && !is_overwrite) {
		std::cout << "The file with same name exists. Are you sure to want overwrite the file? Input please y/n." << std::endl;
		ConsoleInput ci;
		is_overwrite = ci.is_choice_yes();
		if (!is_overwrite) {
			std::cout << "Please input the filename:" << std::endl;
			std::getline(std::cin, filename);
		}
	}
}

bool FileOutput::is_file_exist(std::string filename) {
	std::ifstream infile(filename);
	return infile.good();
}

void FileOutput::write_input_data_to_file(std::ofstream& fout, Text text) {
	text.print(&fout);
}

bool FileOutput::save_input_data_to_file(Text text) {
	std::cout << "Please, input the filename:" << std::endl;
	std::string filename = "";
	getline(std::cin, filename);
	try_overwrite_file(filename);
	std::ofstream fout(filename);
	if (fout.is_open()) {
		std::error_code ec;
		if (!std::filesystem::is_regular_file(filename, ec)) {
			std::cerr << "Sorry, there is a problem with file." << std::endl;
			return false;
		}
		write_input_data_to_file(fout, text);
	} else {
		fout.close();
		return false;
	}
	fout.close();
	return true;
}

bool FileOutput::save_output_data_to_file(Text text) {
	std::cout << "Please input the filename:" << std::endl;
	std::string filename = "";
	std::getline(std::cin, filename);
	try_overwrite_file(filename);
	std::ofstream fout(filename);

	if (fout.is_open()) {
		std::error_code ec;
		if (!std::filesystem::is_regular_file(filename, ec)) {
			std::cout << "Sorry, there is a problem with file." << std::endl;
			return false;
		}
		write_output_data_to_file(fout, text);
	} else {
		fout.close();
		return false;
	}
	fout.close();
	return true;
}

void FileOutput::write_output_data_to_file(std::ofstream& fout, Text text) {
	text.print_info(&fout);
	fout << std::endl;
	text.print_sentences_info(&fout);
}

void FileOutput::save_input_data(Text text) {
	std::cout << "Do you want to save input data to file? Input please y/n." << std::endl;
	ConsoleInput ci;
	bool is_yes = ci.is_choice_yes();

	if (is_yes) {
		bool is_success = save_input_data_to_file(text);

		while (!is_success) {
			std::cerr << "The data didn't save! Try again!" << std::endl;
			is_success = save_input_data_to_file(text);
		}

		std::cout << "The data saved successfully!" << std::endl;
	}
}

void FileOutput::save_output_data(Text text) {
	std::cout << "Do you want to save result to file? Input please y/n:" << std::endl;
	ConsoleInput ci;
	bool is_yes = ci.is_choice_yes();

	if (is_yes) {
		bool is_success = save_output_data_to_file(text);

		while (!is_success) {
			std::cerr << "The data didn't save! Try again!" << std::endl;
			is_success = save_output_data_to_file(text);
		}
		std::cout << "The data saved successfully!" << std::endl;
	}
}