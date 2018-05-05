#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "hashtab.h"
#include "build_hashtab.h"

void dir_tree(char *curr_dir) 
{
	char name[256];
	DIR *dir = opendir(curr_dir), *check_dir;
	struct dirent *files;

	//Поиск файлов
	while ((files = readdir(dir)) != NULL) {
		
		//Исключаем текущий и родительский каталоги
		if (strcmp(files->d_name, ".") && strcmp(files->d_name, "..")) {
			
			//Преобразуем имя файла в относительный адрес
			strcpy(name, files->d_name);
			int curr_dir_length = strlen(curr_dir) + 1;
			int name_length = strlen(name);

			// Перенос новой строки вправо на длину текущей строки
			for (int i = name_length; i >= 0; --i) {
				name[i + curr_dir_length] = name[i];
			}

			for (int i = 0; i < curr_dir_length; ++i){
				name[i] = curr_dir[i];
			}

			name[curr_dir_length - 1] = '/';
			printf("%s\n", name); //temp

			//Проверка на то, является ли элемент папкой или файлом
			check_dir = opendir(name);
			if (check_dir != NULL) {				
				dir_tree(name);
			} else {
				FILE *file = fopen(name, "r");
				build_hashtab(file);
				fclose(file);
			}
			closedir(check_dir);			
		}
	}
	closedir(dir);
}
