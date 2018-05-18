#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "dir_tree.h"
#include "search.h"

int main()
{
	char directory[256] = "./res";
	dir_tree(directory);

	return 0;
}
