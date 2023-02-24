#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "logger.h"

struct stack
{
	int size;
	int capacity;
	int* data;
};
typedef struct stack Stack;


STACK stack_init_default()
{
	Stack* pStack;

	LOG_DEBUG("stack_init_default\n");

	pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
	{
		return NULL;
	}
	pStack->size = 0;

	pStack->data = (int*)malloc(10 * sizeof(int));
	if (pStack->data ==NULL)
	{
		free(pStack);
		return NULL;
	}
	pStack->capacity = 10;

	LOG_DEBUG("stack_init_default created stack %p\n",pStack);

	return pStack;
}

void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;
	LOG_DEBUG("stack_destroy called for %p\n",*phStack);

	free(pStack->data);
	free(pStack);

	*phStack = NULL;
}

Status stack_push(STACK hStack, int value)
{
	Stack* pStack = (Stack*)hStack;
	int* temp;
	int i;

	LOG_DEBUG("stack_push for stack %p value  %d\n",pStack, value);

	if (pStack->size >= pStack->capacity) // need to resize
	{
		LOG_DEBUG("stack_push for stack resizing from %d to  %d\n", pStack->capacity,2* pStack->capacity );

		temp = (int*)malloc(2 * pStack->capacity * sizeof(int));
		if (temp == NULL)
		{
			LOG_CRITICAL("stack_push resize failed\n");
			return FAILURE;
		}
		for (i = 0; i < pStack->size; i++)
			temp[i] = pStack->data[i];

		free(pStack->data);
		pStack->data = temp;
		pStack->capacity *= 2;
	}
	
	pStack->data[pStack->size] = value;
	pStack->size++;

	return SUCCESS;
}

Status stack_pop(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;

	LOG_DEBUG ("stack_pop  \n");

	if (!stack_is_empty(hStack))
	{
		pStack->size--;
		LOG_DEBUG("stack_pop size is now %d  \n", pStack->size);

		return SUCCESS;
	}

	LOG_DEBUG("stack_pop failed \n");

	return FAILURE;
}

int stack_top(STACK hStack, Status* pStatus)
{
	Stack* pStack = (Stack*)hStack;
	LOG_DEBUG("stack_top  \n");

	if (!stack_is_empty(hStack))
	{
		LOG_DEBUG("stack_top succeeded \n");
		if (pStatus != NULL)
			*pStatus = SUCCESS;

		return pStack->data[pStack->size - 1];
	}
	if (pStatus != NULL)
		*pStatus = FAILURE;

	LOG_DEBUG("stack_top failed \n");

	return -99;

}

Boolean stack_is_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;

	LOG_DEBUG("stack_is_empty returns %d \n", pStack->size <= 0);

	return (pStack->size <= 0);
}