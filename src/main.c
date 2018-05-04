#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "build_hashtab.h"
#include "hashtab.h"
#include "dir_tree.h"

int main()
{
	char directory[255] = "./res";
	dir_tree(directory);

	return 0;
}
