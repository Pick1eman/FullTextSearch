#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"

unsigned int *search(char *text, char *sample)
{
	//Находим длины строк
	unsigned int text_length = strlen(text);
	unsigned int sample_length = strlen(sample);

    //Если длина образца больше длины текста, то тщетно бытие
	if (sample_length > text_length) {
		return NULL;
	}

	int br = 0;
    unsigned int index = 0;

    //Выделяем память для массива позиций (не забыть освободить!!!)
    unsigned int *result = (unsigned int*)malloc(sizeof(unsigned int));

	//Пеебираем все возможные подстроки, выполняя сдвиг на один символ
	for (unsigned int i = 0; i <= (text_length - sample_length); ++i) {
		//Выполняем сравнение посимвольно
		for (unsigned int j = 0; j < sample_length; ++j) {
			//Если символы не совпадают, прерываем цикл
			if (sample[j] != text[i + j]) {
				br = 1;
				break;
			}
		}

		//Если совпадение найдено (цикл не был прерван)
		if (!br) {
			//Добавляем индекс начала подстроки
			result[index] = i;
            ++index;
            result = (unsigned int*)realloc(result, (index + 1) * sizeof(unsigned int));
		} else {
			//Иначе сбрасываем счетчик прерываний
			br = 0;
		}
	}

	return result;
}
