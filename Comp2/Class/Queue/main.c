#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "logger.h"


int main()
{
	QUEUE hMyQueue;
	int i;

	hMyQueue = queue_init_default();
	if (hMyQueue == NULL)
	{
		LOG_CRITICAL("queue_init_default failed \n");
		exit(1);
	}

	for (i = 0; i < 35; i++)
		queue_enqueue(hMyQueue, i);

	printf("\n**\nsize is now %d \n****\n", queue_get_size(hMyQueue));

	for (i = 0; i < 10; i++)
	{
		if (!queue_is_empty(hMyQueue))
			printf("Queue front is %d\n", queue_front(hMyQueue, NULL));
		queue_service(hMyQueue);
	}


	printf("\n**\nsize is now %d \n****\n", queue_get_size(hMyQueue));
	for (i = 16; i < 36; i++)
		queue_enqueue(hMyQueue, i);


	printf("\n**\nsize is now %d \n****\n", queue_get_size(hMyQueue));
	for (i = 0; i < 10; i++)
	{
		if (!queue_is_empty(hMyQueue))
			printf("Queue front is %d\n", queue_front(hMyQueue, NULL));
		queue_service(hMyQueue);
	}


	printf("\n**\nsize is now %d \n****\n", queue_get_size(hMyQueue));

	queue_output(hMyQueue);

	queue_destroy(&hMyQueue);
	return 0;
}
