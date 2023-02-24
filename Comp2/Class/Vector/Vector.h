
#ifndef VECTOR_H
#define VECTOR_H

#include "Status.h"

typedef void * VECTOR;

VECTOR vector_init_default(void);
void vector_destroy(VECTOR* phVEctor);

Status vector_push_back(VECTOR hVector, int value);
void vector_output(VECTOR hVector);
int* vector_at(VECTOR hVector, int index);
Status vector_pop_back(VECTOR hVector);
Boolean vector_is_empty(VECTOR hVector);
int vector_get_size(VECTOR hVector);
int vectot_get_capacity(VECTOR hVector);


#endif 
