#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "hashtab.h"
#include "build_hashtab.h"
#include "dir_tree.h"

listnode *arr_hashtab[HASHTAB_SIZE];

int main()
{
	char directory[256] = "./res";
	dir_tree(directory);

	hashtab_print(arr_hashtab);

	hashtab_free(arr_hashtab);

	return 0;
}
