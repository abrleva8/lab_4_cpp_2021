#ifndef _FILE_OUTPUT_H_
#define _FILE_OUTPUT_H_

#include <string>
#include <vector>
#include "text_analyzer.h"

typedef std::vector < std::vector <double> > Matrix;

// Класс реализующий запись данных в файл
class FileOutput {
private:
	// Проверяет ли файл с именем @filename
	// Если есть - уточняет стоит ли перезаписывать
	// Если нет - ничего не делает
	void try_overwrite_file(std::string& filename);

	// Возвращает, существует ли файл с именем/путем @filename
	bool is_file_exist(std::string filename);

	// Записывает в данный файл входные данные
	void write_input_data_to_file(std::ofstream& fout, Text text);

	// Метод, который сохраняет входные данные в файл
	// Если что-то не получилось возвращает @false
	bool save_input_data_to_file(Text text);

	// Метод, который сохраняет выходные данные в файл
	// Если что-то не получилось возвращает @false
	bool save_output_data_to_file(Text text);

	// Записывает в данный файл выходные данные
	void write_output_data_to_file(std::ofstream& fout, Text text);
public:
	// Метод запускающий процедуру сохранения входных данных в файл
	void save_input_data(Text text);

	// Метод запускающий процедуру сохранения выходных данных в файл
	void save_output_data(Text text);
};

#endif