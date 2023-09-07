#ifndef _FILE_OUTPUT_H_
#define _FILE_OUTPUT_H_

#include "text_analyzer.h"

// Класс реализующий запись данных в файл
class FileOutput {
private:
	// Проверяет ли файл с именем @filename
	// Если есть - уточняет стоит ли перезаписывать
	// Если нет - ничего не делает
	static void try_overwrite_file(std::string& filename);

	// Возвращает, существует ли файл с именем/путем @filename
	static bool is_file_exist(const std::string& filename);

	// Записывает в данный файл входные данные
	static void write_input_data_to_file(std::ofstream& fout, Text text);

	// Метод, который сохраняет входные данные в файл
	// Если что-то не получилось возвращает @false
	[[nodiscard]] static bool save_input_data_to_file(Text text);

	// Метод, который сохраняет выходные данные в файл
	// Если что-то не получилось возвращает @false
	[[nodiscard]] static bool save_output_data_to_file(const Text& text);

	// Записывает в данный файл выходные данные
	static void write_output_data_to_file(std::ofstream& fout, Text text);
public:
	// Метод запускающий процедуру сохранения входных данных в файл
	static void save_input_data(const Text& text);

	// Метод запускающий процедуру сохранения выходных данных в файл
	static void save_output_data(const Text& text);
};

#endif