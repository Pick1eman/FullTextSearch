#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtab.h"

listnode *hashtab[HASHTAB_SIZE];

unsigned int hashtab_hash(char *key)
{
	unsigned int hash = 0;
	char *pointer;

	for (pointer = key; *pointer != '\0'; pointer++) {
		hash = hash * HASHTAB_MUL + (unsigned int)*pointer;
	}

	return hash % HASHTAB_SIZE;
}

void hashtab_init(listnode **hashtab)
{
	//Инициализация массива указателей NULL'ами
	for (int i = 0; i < HASHTAB_SIZE; ++i) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(listnode **hashtab, char *key, int value)
{
	listnode *new_node; //Новый (добавляемый) нод
	int index = hashtab_hash(key), key_length; //Индекс нового нода

	new_node = (listnode*)malloc(sizeof(listnode));

	//Если удалось выделить память для нового нода
	if (new_node) {
		//Если элемент под данным индексом уже есть (т.е. в случае коллизии)
		if (hashtab[index]) {
			listnode *curr_node = hashtab[index];
			//Находим конец связного списка
			while (1) {
				if (!curr_node->next) {
					//К последнему его элементу "прикрепляем" новый 
					curr_node->next = new_node;
					break;
				}
				curr_node = curr_node->next;
			}
		//Если коллизии нет
		} else {
			//Присваиваем эл-ту под нужным индексом указатель на новый нод
			hashtab[index] = new_node;
		}
		//Инициализируем новый нод входными данными
		new_node->next = NULL;
		new_node->value = value;
		key_length = strlen(key) + 1;
		new_node->key = (char*)malloc(key_length * sizeof(char));
		strcpy(new_node->key, key);
	}
}

listnode *hashtab_lookup(listnode **hashtab, char *key)
{
	listnode *wanted_node; //Искомый нод
	int index = hashtab_hash(key); //индекс искомого нода

	//wanted_node = (listnode*)malloc(sizeof(listnode));

	//Проходимся по цепочке до обнаружения конца (NULL)
	for (wanted_node = hashtab[index]; wanted_node; wanted_node = wanted_node->next) {
		//Если обнаружено совпадение с key
		if (!(strcmp(wanted_node->key, key))) {
			//Возвращаем указатель на найденный нод
			return wanted_node;
		}
	}

	return NULL;
}

void hashtab_free(listnode **hashtab)
{
	listnode *curr_node, *prev_node;

	for (unsigned int i = 0; i < HASHTAB_SIZE; ++i) {
		curr_node = hashtab[i];
		if (curr_node) {
			while (curr_node->next) {
				prev_node = curr_node;
				curr_node = curr_node->next;
				free(prev_node->key);
				free(prev_node);
			}
			free(curr_node->key);
			free(curr_node);
		}
	}
	free(hashtab);
}

void hashtab_print(listnode **hashtab)
{
	listnode *curr_node;

	for (unsigned int i = 0; i < HASHTAB_SIZE; ++i) {
		curr_node = hashtab[i];
		if (curr_node) {
			printf("Node[%d]\n", i);
			while (curr_node->next) {
				curr_node = curr_node->next;
				printf("key = %s\nvalue = %d\n", curr_node->key, curr_node->value);
			}
			printf("key = %s\nvalue = %d\n", curr_node->key, curr_node->value);
		}
	}
}
