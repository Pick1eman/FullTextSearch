#define CTEST_MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include "int_vector.h"
#include "output.h"
#include "traversal.h"
#include "search.h"
#include "ctest.h"

char *sample;

int r = 0, h = 0;

extern size_t general_counter;


int main(int argc, const char** argv)
{
	int test_result = ctest_main(argc, argv);
	return test_result;
}
