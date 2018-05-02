#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtab.h"
#include "build_hashtab.h"

int main()
{	
	//Открываем файлы с входными данными
	FILE *words;
	words = fopen("./res/words.txt", "r");

	listnode **hashtab = (listnode**)malloc(HASHTAB_SIZE * sizeof(listnode*)); //Выделяем память на хеш таблицу

	build_hashtab(hashtab, words);

	printf("Hashtab:\n");
	hashtab_print(hashtab);
	printf("\n");

	hashtab_free(hashtab);

	return 0;
}
