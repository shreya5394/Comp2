#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"
#include "Status.h"
#include "logger.h"


struct vector
{
	int capacity;
	int size;
	int* data;
};
typedef struct vector Vector;


VECTOR vector_init_default(void)
{
	Vector* pVector = NULL;;

	pVector = (Vector*) malloc(sizeof(Vector ));
	if (pVector == NULL)
	{
		printf("vector_init_default failed - returning NULL\n");
		return NULL;
	}
	pVector->capacity = 10;
	pVector->size = 0;
	pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);
	if (pVector->data == NULL)
	{
		free(pVector);
		printf("vector_init_default failed creating internal array - returning NULL\n");
		return NULL;
	}

	return pVector;
}

void vector_destroy(VECTOR* phVector)
{
	Vector* pVector = (Vector*) *phVector;

	free(pVector->data);
	pVector->data = NULL;
	free(pVector);
	*phVector = NULL;
	printf("vector_destroyed \n");
}

Status vector_push_back(VECTOR hVector, int value)
{
	Vector* pVector = (Vector*)hVector;
	int* temp;
	int i;

	if (pVector->size >= pVector->capacity) // resize
	{
		LOG_DEBUG("vector resizing to %d\n", pVector->capacity * 2);
		temp = (int*) malloc(pVector->capacity * 2* sizeof(int) );
		if (temp == NULL)
		{
			LOG_CRITICAL("vector resize failed \n");
			return FAILURE;
		}
		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];
		}
		free(pVector->data);
		pVector->data = temp;
		pVector->capacity *= 2;
	}

	pVector->data[pVector->size] = value;;
	pVector->size++;

	return SUCCESS;
}

void vector_output(VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;
	int i;
	for (i = 0; i < pVector->size; i++)
		printf("vector [%d] is %d\n", i, pVector->data[i]);
}

int* vector_at(VECTOR hVector, int index)
{
	Vector* pVector = (Vector*)hVector;
	if (index >= 0 && index < pVector->size)
		return &pVector->data[index];
	else
	{
		LOG_CRITICAL("invalid index %d in vector_at\n", index);
		return NULL;

	}
}

Status vector_pop_back(VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;

	if (!vector_is_empty(hVector))
	{
		pVector->size--;
		return SUCCESS;
	}

	return FAILURE;
}

Boolean vector_is_empty(VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;

	return (Boolean)(pVector->size <= 0);
}

int vector_get_size(VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;
	return pVector->size;
}
int vectot_get_capacity(VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;
	return pVector->capacity;
}
