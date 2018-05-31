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




CTEST(serach1, correct)
{
	IntVector *result = search("Hello world!\n", "world");
	unsigned int expected = 6;
	size_t expected1 = 1;
	ASSERT_EQUAL_U(expected,result->arr[0]);
	ASSERT_EQUAL_U(expected1,result->size);
	ASSERT_EQUAL_U(expected1,result->capacity);
	int_vector_free(result);
}



CTEST(serach2, correct)
{
	IntVector *result = search("Kill gunslinger\n", "er\n");
	unsigned int expected = 13;
	size_t expected1 = 1;
	ASSERT_EQUAL_U(expected,result->arr[0]);
	ASSERT_EQUAL_U(expected1,result->size);
	ASSERT_EQUAL_U(expected1,result->capacity);
	int_vector_free(result);
}

CTEST(serach3, correct)
{
	IntVector *result = search("Kill gunslinger\n", "Ki");
	unsigned int expected = 0;
	size_t expected1 = 1;
	ASSERT_EQUAL_U(expected,result->arr[0]);
	ASSERT_EQUAL_U(expected1,result->size);
	ASSERT_EQUAL_U(expected1,result->capacity);
	int_vector_free(result);
}

CTEST(serach4, correct)
{
	IntVector *result = search("A nu cheeki breeki i v damke!\n", "monolith");
	size_t expected1 = 0;
	size_t expected2 = 1;
	ASSERT_EQUAL_U(expected1,result->size);
	ASSERT_EQUAL_U(expected2,result->capacity);
	int_vector_free(result);
}


CTEST(serach5, correct)
{
	IntVector *result = search("Yuri\nSemetsky\n", "i\nS");
	unsigned int expected = 3;
	size_t expected1 = 1;
	ASSERT_EQUAL_U(expected,result->arr[0]);
	ASSERT_EQUAL_U(expected1,result->size);
	ASSERT_EQUAL_U(expected1,result->capacity);
	int_vector_free(result);
}




CTEST(string_tolower1, correct)
{
	char *result = (char*)malloc(24 * sizeof(char));
	strcpy(result, "NLC 7:i'm Markered One\n");
	result = string_tolower(result);
	char *expected = (char*)malloc(24 * sizeof(char));
	strcpy(expected, "nlc 7:i'm markered one\n");
	ASSERT_STR(expected, result);
	free(expected);
	free(result);
}


















int main(int argc, const char** argv)
{
	int test_result = ctest_main(argc, argv);
	return test_result;
}
