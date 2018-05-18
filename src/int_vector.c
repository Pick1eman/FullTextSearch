#include <stdio.h>
#include <stdlib.h>
#include "int_vector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
	IntVector *v = (IntVector*)malloc(sizeof(IntVector));

	v->arr = (unsigned int*)malloc(initial_capacity * sizeof(unsigned int));

	if (v->arr != 0) {
		v->capacity = initial_capacity;
		v->size = 0;
		return v;
	} else {
		return NULL;
	}
}

int int_vector_push_back(IntVector *v, unsigned int item)
{
	if (v->size == v->capacity) {
		v->arr = (unsigned int*)realloc(v->arr, (v->capacity + 1) * sizeof(unsigned int));
		if (v->arr != 0) {
			++v->capacity;
			++v->size;
			v->arr[v->size - 1] = item;
			return 0;
		} else {
			return -1;
		}
	} else if (v->size < v->capacity) {
		++v->size;
		v->arr[v->size - 1] = item;
		return 0;
	} else {
		return 0;
	}
}

void int_vector_free(IntVector *v)
{
	free(v->arr);
	free(v);
}
