#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "dir_tree.h"



int main()
{
	char directory[255] = "./res";
	dir_tree(directory);

	return 0;
}
