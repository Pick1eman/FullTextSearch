#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "strings.h"
#include "int_vector.h"
#include "output.h"
#include "traversal.h"
#include "search.h"

extern char *sample;

extern int r, h;

char *file_to_string(FILE *file)
{
	unsigned int i;
	char *string = (char*)malloc(1 * sizeof(char));

	for (i = 0; fscanf(file, "%c", &string[i]) != EOF; ++i) {
		string = (char*)realloc(string, (i + 2) * sizeof(char));
	}
	string[i] = '\0';

	return string;
}

char *string_tolower(char *string)
{
	for (unsigned int i = 0; string[i] != '\0'; ++i) {
		string[i] = tolow(string[i]);
	}

	return string;
}

void traversal_file(char *file_name)
{
	FILE *file = fopen(file_name, "r"); //Открываем файл
	char *text = file_to_string(file); //Формируем из файла строку
	fclose(file);	
	
	text = string_tolower(text);
	sample = string_tolower(sample);

	IntVector *result = search(text, sample); //Передаем текст и образец в функцию поиска
	
	result_output(file_name, text, result); //Текст и полученный вектор передаем в выводящую функцию

	int_vector_free(result);				
	free(text);
}

void traversal(char *dir_name)
{
	DIR *dir = opendir(dir_name), *check_dir = NULL;
	struct dirent *files;

	//Перебор элементов
	while ((files = readdir(dir)) != NULL) {

		//Исключаем текущий и родительский каталоги
		if (scmp(files->d_name, ".") && scmp(files->d_name, "..")) {
			//Ключ -h. Проверка, является ли файл (папка) скрытым
			if ((!h) && (files->d_name[0] == '.')) {
				continue;
			}

			//Преобразуем имя файла в относительный адрес
			int name_length = slen(files->d_name);
			char *name = (char*)malloc((name_length + 1) * sizeof(char));
			scpy(name, files->d_name);
			int dir_name_length = slen(dir_name);

			// Перенос новой строки вправо на длину текущей строки
			name_length = name_length + dir_name_length + 1;
			name = (char*)realloc(name, (name_length + 1) * sizeof(char));
			for (int i = slen(files->d_name); i >= 0; --i) {
				name[i + dir_name_length + 1] = name[i];
			}

			for (int i = 0; i < dir_name_length; ++i) {
				name[i] = dir_name[i];
			}

			name[dir_name_length] = '/';

			//Проверка на то, является ли элемент папкой или файлом
			check_dir = opendir(name);
			if (check_dir != NULL) {
				//Рекурсия выполняется только если есть ключ -r
				if (r) {
					traversal(name);
				}
			} else {
				traversal_file(name);
			}
			closedir(check_dir);
			free(name);
		}
	}
	closedir(dir);
}
