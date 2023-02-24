#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "logger.h"


int main()
{
	STACK hMyStack;

	hMyStack = stack_init_default();
	if (hMyStack == NULL)
	{
		LOG_CRITICAL("stack_init_default failed \n");
		exit(1);
	}

	stack_push(hMyStack, 56);
	stack_push(hMyStack, 3);
	stack_push(hMyStack, 21);

	stack_pop(hMyStack);

	if (!stack_is_empty(hMyStack))
		printf("Stack top is %d\n", stack_top(hMyStack, NULL));

	stack_pop(hMyStack);

	if (!stack_is_empty(hMyStack))
		printf("Stack top is %d\n", stack_top(hMyStack, NULL));


	stack_destroy(&hMyStack);
	return 0;
}
