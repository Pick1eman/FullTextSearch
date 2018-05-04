#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "dir_tree.h"
#include <stdlib.h>


void dir_tree(char *curr_dir) 
{
	int count = 0;
	char next_dir[255];
	DIR *dir;
	FILE *file;
	struct dirent *files;
	dir = opendir(curr_dir);

	while ((files = readdir(dir)) != NULL) {//Поиск файлов

		if ((strcmp(files->d_name, ".")) && (strcmp(files->d_name, ".."))){
			printf("%s\n", files->d_name);
			/*for (int i = 0; i < strlen(files->d_name) + 1; ++i){
					//Применить для проверки файла fopen
				if (files->d_name[i] == '.') {
					count++;
				}
			}*/


			file = fopen(name_file, "r");
			if (file != NULL) {
				count = 1;
			} else { 
				count = 0; 
			}

			if (count == 1) {
				strcpy(next_dir, files->d_name);
				int curr_dir_length = strlen(curr_dir) + 1;
				int next_dir_length = strlen(next_dir);

				// Перенос новой строки вправо на длину текущей строки 
				for (int i = next_dir_length; i >= 0; --i) {
					next_dir[i+curr_dir_length] = next_dir[i];
				}
				for (int i = 0; i < curr_dir_length; ++i){
					next_dir[i] = curr_dir[i];
				}
				next_dir[curr_dir_length - 1] = '/';
				printf("%s\n", next_dir);
				dir_tree(next_dir);				
			}
			count = 0;			
		}
	}
	closedir(dir);

}


	
