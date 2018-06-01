#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "strings.h"
#include "int_vector.h"
#include "output.h"
#include "traversal.h"
#include "search.h"

/*
Вывод в формате:
<имя_файла>: <число_совпадений>
<номер_строки>-<номер_символа>
*/

size_t general_counter = 0;

void beginning_output(char *dir_name)
{
	FILE *log = fopen("./logs/user.log", "w");
	//fprintf(log, "         Output format\n _____________________________\n|<file_name>: <matches_number>|\n|<line>-<character>           |\n|_____________________________|\n\n");
	fprintf(log, "Target directory: %s\n\n", dir_name);
	fclose(log);
}

void result_output(char *file_name, char *text, IntVector *result)
{
	FILE *log = fopen("./logs/user.log", "a");
	fprintf(log, "%s: ", file_name);
	
	//Если result->size = 0, значит совпадения не были найдены
	if (!result->size) {
		fprintf(log, "0\nNo matches found\n");
	} else {
		fprintf(log, "%zd\n", result->size);
		general_counter += result->size;

		unsigned int text_length = slen(text) + 1;
		unsigned int str_num = 1; //Переменная считает номер строки
		unsigned int char_num = 0; //Переменная считает номер символа в строке
		unsigned int result_index = 0; //Счетчик увеличивается каждый раз при выводе индекса в файл

		for (unsigned int i = 0; i < text_length; ++i) {
			++char_num;
			if (text[i] == '\n') {
				++str_num;
				char_num = 0;
			}
			if (i == result->arr[result_index]) {
				fprintf(log, "%u-%u\n", str_num, char_num);
				++result_index;
				//Вывод всей строки в которой найдено совпадение. Не знаю, нужно ли? Пока закомментил
				/*for (unsigned int j = i - char_num + 1; ((text[j] != '\n') && (text[j] != '\0')); ++j) {
					fprintf(log, "%c", text[j]);
				}
				fprintf(log, "\n");*/
			}
		}
	}
	fprintf(log, "\n");

	fclose(log);
}

void ending_output()
{
	FILE *log = fopen("./logs/user.log", "a");
	fprintf(log, "Total: %zd\n", general_counter);
	fclose(log);
}
