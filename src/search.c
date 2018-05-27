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

	//Создаем вектор для записи индексов начал совпадающих подстрок
	IntVector *result = int_vector_new(1);

	//Если длина образца больше длины текста, то совпадений быть не может
	if (sample_length > text_length) {
		return result;
	}

	//Пеебираем все возможные подстроки, выполняя сдвиг на один символ
	for (unsigned int i = 0; i <= (text_length - sample_length); ++i) {
		//Выполняем сравнение посимвольно
		unsigned int j;
		for (j = 0; j < sample_length; ++j) {
			//Если символы не совпадают, прерываем цикл
			if (sample[j] != text[i + j]) {
				break;
			}
		}

		//Если совпадение найдено (цикл не был прерван)
		if (j == sample_length) {
			//Добавляем индекс начала подстроки
			int_vector_push_back(result, i);
		}
	}

	return result;
}
