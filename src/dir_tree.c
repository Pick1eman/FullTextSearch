#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "dir_tree.h"
#include <stdlib.h>


void dir_tree(char *curr_dir) 
{
	char name[256];
	DIR *dir, *check_dir;
	FILE *file;
	struct dirent *files;
	dir = opendir(curr_dir);

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
				closedir(check_dir);
			} else {
				file = fopen(name, "r");
				printf("build_hashtab()\n"); //temp
				fclose(file);
			}			
		}
	}
	closedir(dir);
}
