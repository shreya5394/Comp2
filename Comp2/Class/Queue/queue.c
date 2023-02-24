#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "logger.h"

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

struct queue
{
	Node* head;
	Node* tail;
	int size;
};

typedef struct queue Q;

QUEUE queue_init_default()
{
	Q* pQ = (Q*)malloc(sizeof(Q));
	if (pQ != NULL)
	{
		pQ->head = NULL;
		pQ->tail = NULL;
		pQ->size = 0;
		return pQ;
	}
	return NULL;
}


void queue_destroy_helper(Node* head)
{
	if (head == NULL)
		return;
	queue_destroy_helper(head->next);
	free(head);
}

void queue_destroy(QUEUE* phQueue)
{
	Q* pQ = (Q*)*phQueue;
	Node* temp;
	queue_destroy_helper(pQ->head);

	/*
	while (pQ->head != NULL)
	{
		temp = pQ->head->next;
		free(pQ->head);
		pQ->head = temp;
	}
	*/
	*phQueue = NULL;
}

Status queue_enqueue(QUEUE hQueue, int value)
{
	//tail_add
	Q* pQ = (Q*)hQueue;
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL)
	{
		LOG_CRITICAL("malloc failed \n");
		return FAILURE;
	}
	pNewNode->next = NULL;
	pNewNode->data = value;

	LOG_DEBUG("enqueuing %d\n", value);

	if (pQ->head == NULL)
	{
		pQ->head = pNewNode;
		pQ->tail = pNewNode;
	}
	else
	{

		pQ->tail->next = pNewNode;
		pQ->tail = pNewNode;
	}
	pQ->size++;
	return SUCCESS;
}

Status queue_service(QUEUE hQueue)
{
	// remove head
	Q* pQ = (Q*)hQueue;
	Node* temp;

	if (pQ->head != NULL)
	{
		temp = pQ->head->next;
		free(pQ->head);
		pQ->head = temp;
		pQ->size--;
		return SUCCESS;
	}
	return FAILURE;
}

int queue_front(QUEUE hQueue, Status* pStatus)
{
	Q* pQ = (Q*)hQueue;

	if (pQ->head == NULL)
	{
		if (pStatus != NULL)
			*pStatus = FAILURE;
		return -9999;
	}
	if (pStatus != NULL)
		*pStatus = SUCCESS;
	LOG_DEBUG("front is %d\n", pQ->head->data);
	return pQ->head->data;
}

Boolean queue_is_empty(QUEUE hQueue)
{
	Q* pQ = (Q*)hQueue;
	return (Boolean)pQ->head == NULL;
}

int queue_get_size(QUEUE hQueue)
{
	Q* pQ = (Q*)hQueue;
	return pQ->size;
}

void queue_output_helper(Node* head)
{
	if (head == NULL)
		return;
	queue_output_helper(head->next);
	printf("%d\n", head->data);

}

void queue_output(QUEUE hQueue)
{
	Q* pQ = (Q*)hQueue;
	queue_output_helper(pQ->head);


}