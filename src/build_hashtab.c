#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtab.h"
#include "build_hashtab.h"

extern listnode *arr_hashtab[HASHTAB_SIZE];

void build_hashtab(FILE *input)
{
    char *key;
	int key_length;
	key = (char*)malloc(STRING_LENGTH * sizeof(char)); //Выделяем STRING_LENGTH байт на строку
	hashtab_init(arr_hashtab); //Создаем хеш таблицу

	//Читаем элементы и добавляем их к таблице
	for (int i = 0; i < SIZE; ++i) {
		key = (char*)realloc(key, STRING_LENGTH * sizeof(char)); //Перевыделяем STRING_LENGTH байт на строку
		fscanf(input, "%s", key); //Читаем строку
		key_length = strlen(key) + 1; //Узнаем необходимую для строки длину
		key = (char*)realloc(key, key_length * sizeof(char)); //Перераспределяем память, убирая ненужное
        //printf("key = %s\nvalue = %d\n", key, i);
		hashtab_add(arr_hashtab, key, i); //Добавляем элемент к таблице
	}
    free(key);
}
