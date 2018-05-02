#pragma once

typedef struct listnode {
	int value;
	char *key;
	struct listnode *next;
} listnode;

#define HASHTAB_SIZE 10000
#define HASHTAB_MUL 31

extern listnode *hashtab[HASHTAB_SIZE];

unsigned int hashtab_hash(char *key);

void hashtab_init(listnode **hashtab);

void hashtab_add(listnode **hashtab, char *key, int value);

listnode *hashtab_lookup(listnode **hashtab, char *key);

void hashtab_free(listnode **hashtab);