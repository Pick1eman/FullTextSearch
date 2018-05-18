#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "hashtab.h"
#include "build_hashtab.h"

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

                FILE *file = fopen(name, "r");
                //Раньше были времена,а теперь мгновение,раньше помню хуй стоял,а теперь давление
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

                FILE *file = fopen(name, "r");
				//Раньше были времена,а теперь мгновение,раньше помню хуй стоял,а теперь давление
            }
            closedir(check_dir);
            free(name);
        }
    }
    closedir(dir);
}
