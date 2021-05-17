#ifndef _FILE_OUTPUT_H_
#define FILE_OUTPUT_H

#include <string>
#include <vector>
#include "text_analyzer.h"

typedef std::vector < std::vector <double> > Matrix;

// ����� ����������� ������ ������ � ����
class FileOutput {
private:
	// ��������� �� ���� � ������ @filename
	// ���� ���� - �������� ����� �� ��������������
	// ���� ��� - ������ �� ������
	void try_overwrite_file(std::string& filename) const;

	// ����������, ���������� �� ���� � ������/����� @filename
	static bool is_file_exist(std::string filename);

	// ���������� � ������ ���� ������� ������
	static void write_input_data_to_file(std::ofstream& fout, Text text);

	// �����, ������� ��������� ������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	bool save_input_data_to_file(Text text);

	// �����, ������� ��������� �������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	bool save_output_data_to_file(Text text);

	// ���������� � ������ ���� �������� ������
	static void write_output_data_to_file(std::ofstream& fout, Text text);
public:
	// ����� ����������� ��������� ���������� ������� ������ � ����
	void save_input_data(Text text);

	// ����� ����������� ��������� ���������� �������� ������ � ����
	void save_output_data(Text text);
};

#endif