#ifndef _FILE_OUTPUT_H_
#define _FILE_OUTPUT_H_

#include "text_analyzer.h"

// ����� ����������� ������ ������ � ����
class FileOutput {
private:
	// ��������� �� ���� � ������ @filename
	// ���� ���� - �������� ����� �� ��������������
	// ���� ��� - ������ �� ������
	static void try_overwrite_file(std::string& filename);

	// ����������, ���������� �� ���� � ������/����� @filename
	static bool is_file_exist(const std::string& filename);

	// ���������� � ������ ���� ������� ������
	static void write_input_data_to_file(std::ofstream& fout, Text text);

	// �����, ������� ��������� ������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	[[nodiscard]] static bool save_input_data_to_file(Text text);

	// �����, ������� ��������� �������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	[[nodiscard]] static bool save_output_data_to_file(const Text& text);

	// ���������� � ������ ���� �������� ������
	static void write_output_data_to_file(std::ofstream& fout, Text text);
public:
	// ����� ����������� ��������� ���������� ������� ������ � ����
	static void save_input_data(const Text& text);

	// ����� ����������� ��������� ���������� �������� ������ � ����
	static void save_output_data(const Text& text);
};

#endif