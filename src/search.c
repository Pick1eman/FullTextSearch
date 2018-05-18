#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int_vector.h"
#include "search.h"

IntVector *search(char *text, char *sample)
{
	//Находим длины строк
	unsigned int text_length = strlen(text);
	unsigned int sample_length = strlen(sample);

    //Если длина образца больше длины текста, то тщетно бытие
	if (sample_length > text_length) {
		return NULL;
	}

	int br = 0;

    IntVector *result = int_vector_new(1);

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
			printf("%d\n", i); //temp
			//Добавляем индекс начала подстроки
			int_vector_push_back(result, i);
		} else {
			//Иначе сбрасываем счетчик прерываний
			br = 0;
		}
	}

	return result;
}
