#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "int_vector.h"
#include "output.h"
#include "dir_tree.h"
#include "search.h"

extern char *sample;

extern int r, h, s;

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

 /*
 Убрать дублирующиеся функции!!!
 Для всех ключей сделать одну универсальную функцию
 Наличие/отсутствие того или иного ключа записать в глобальную переменную
 В функции сделать проверку наличия ключей, в зависимости от этого выполнять что требуется
 */

void direction(char *dir_name)
{
	DIR *dir = opendir(dir_name), *check_dir = NULL;
	struct dirent *files;

	//Перебор элементов
	while ((files = readdir(dir)) != NULL) {

		//Исключаем текущий и родительский каталоги
		if (strcmp(files->d_name, ".") &&  strcmp(files->d_name, "..")) {

			//Преобразуем имя файла в относительный адрес
			int name_length = strlen(files->d_name);
			char *name = (char*)malloc((name_length + 1) * sizeof(char));
			strcpy(name, files->d_name);
			int dir_name_length = strlen(dir_name);

			// Перенос новой строки вправо на длину текущей строки
			name_length = name_length + dir_name_length + 1;
			name = (char*)realloc(name, (name_length + 1) * sizeof(char));
			for (int i = strlen(files->d_name); i >= 0; --i) {
				name[i + dir_name_length + 1] = name[i];
			}

			for (int i = 0; i < dir_name_length; ++i) {
				name[i] = dir_name[i];
			}

			name[dir_name_length] = '/';

			//Проверка на то, является ли элемент папкой или файлом
			check_dir = opendir(name);
			if (check_dir != NULL) {
				
			} else {
				FILE *log = fopen("./logs/user.log", "a");
				fprintf(log, "%s\n", name);
				fclose(log);
				
				FILE *file = fopen(name, "r"); //Открываем файл				
				char *text = file_to_string(file); //Формируем из файла строку
				fclose(file);
				
				IntVector *result = search(text, sample); //Передаем текст и образец в функцию поиска
				
				file_output(text, result); //Текст и полученный вектор передаем в выводящую функцию

				int_vector_free(result);				
				free(text);
			}
			closedir(check_dir);
			free(name);
		}
	}
	closedir(dir);
}

void direction_recurs(char *dir_name)
{
	DIR *dir = opendir(dir_name), *check_dir = NULL;
	struct dirent *files;

	//Перебор элементов
	while ((files = readdir(dir)) != NULL) {

		//Исключаем текущий и родительский каталоги
		if ( strcmp(files->d_name, ".") &&  strcmp(files->d_name, "..")) {

			//Преобразуем имя файла в относительный адрес
			int name_length = strlen(files->d_name);
			char *name = (char*)malloc((name_length + 1) * sizeof(char));
			strcpy(name, files->d_name);
			int dir_name_length = strlen(dir_name);

			// Перенос новой строки вправо на длину текущей строки
			name_length = name_length + dir_name_length + 1;
			name = (char*)realloc(name, (name_length + 1) * sizeof(char));
			for (int i = strlen(files->d_name); i >= 0; --i) {
				name[i + dir_name_length + 1] = name[i];
			}

			for (int i = 0; i < dir_name_length; ++i) {
				name[i] = dir_name[i];
			}

			name[dir_name_length] = '/';

			//Проверка на то, является ли элемент папкой или файлом
			check_dir = opendir(name);
			if (check_dir != NULL) {
				direction_recurs(name);
			} else {
				FILE *log = fopen("./logs/user.log", "a");
				fprintf(log, "%s\n", name);
				fclose(log);
				
				FILE *file = fopen(name, "r"); //Открываем файл				
				char *text = file_to_string(file); //Формируем из файла строку
				fclose(file);
				
				IntVector *result = search(text, sample); //Передаем текст и образец в функцию поиска
				
				file_output(text, result); //Текст и полученный вектор передаем в выводящую функцию

				int_vector_free(result);				
				free(text);
			}
			closedir(check_dir);
			free(name);
		}
	}
	closedir(dir);
}
