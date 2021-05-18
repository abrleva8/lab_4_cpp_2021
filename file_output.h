#ifndef _FILE_OUTPUT_H_
#define _FILE_OUTPUT_H_

#include <string>
#include "text_analyzer.h"

// ����� ����������� ������ ������ � ����
class FileOutput {
private:
	// ��������� �� ���� � ������ @filename
	// ���� ���� - �������� ����� �� ��������������
	// ���� ��� - ������ �� ������
	void try_overwrite_file(std::string& filename) const;

	// ����������, ���������� �� ���� � ������/����� @filename
	static bool is_file_exist(const std::string& filename);

	// ���������� � ������ ���� ������� ������
	static void write_input_data_to_file(std::ofstream& fout, Text text);

	// �����, ������� ��������� ������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	[[nodiscard]] bool save_input_data_to_file(Text text) const;

	// �����, ������� ��������� �������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	[[nodiscard]] bool save_output_data_to_file(Text text) const;

	// ���������� � ������ ���� �������� ������
	static void write_output_data_to_file(std::ofstream& fout, Text text);
public:
	// ����� ����������� ��������� ���������� ������� ������ � ����
	void save_input_data(const Text& text) const;

	// ����� ����������� ��������� ���������� �������� ������ � ����
	void save_output_data(const Text& text) const;
};

#endif