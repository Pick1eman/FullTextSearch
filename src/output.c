#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
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

void file_output(char *text, IntVector *result)
{
	FILE *log = fopen("./logs/user.log", "a");
	
	//Если result->size = 0, значит совпадения не были найдены
	if (!result->size) {
		fprintf(log, "0\nNo matches found\n");
	} else {
		fprintf(log, "%zd\n", result->size);
		general_counter += result->size;

		unsigned int text_length = strlen(text) + 1;
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
			}
		}
	}
	fprintf(log, "\n");

	fclose(log);
}
