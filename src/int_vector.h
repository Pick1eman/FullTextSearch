#pragma once

typedef struct {
	unsigned int *arr;
	size_t size, capacity;
}IntVector;

IntVector *int_vector_new(size_t initial_capacity);

int int_vector_push_back(IntVector *v, unsigned int item);

void int_vector_free(IntVector *v);
