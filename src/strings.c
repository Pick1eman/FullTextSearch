#include <stdio.h>
#include "strings.h"

unsigned int slen(char *string)
{
	unsigned int length = 0;
	while (string[length] != '\0') {
		++length;
	}
	return length;
}

void scpy(char *string1, char *string2)
{
	unsigned int i;
	for (i = 0; string2[i] != '\0'; ++i) {
		string1[i] = string2[i];
	}
	string1[i] = string2[i];
}

int scmp(char *string1, char *string2) //0 - если строки одинаковы, -1 - если различны
{
	if (slen(string1) != slen(string2)) {
		return -1;
	}

	unsigned int length = slen(string1) + 1, counter = 0;

	for (unsigned int i = 0; i < length; ++i) {
		if (string1[i] == string2[i]) {
			++counter;
		}
	}

	if (counter == length) {
		return 0;
	} else {
		return -1;
	}
}

char tolow(char ch)
{
	if ((ch >= 'A') && (ch <= 'Z')) {
		ch += 32;
	}

	return ch;
}
