#include "Status.h"

typedef void* QUEUE;

QUEUE queue_init_default();
void queue_destroy(QUEUE* phQueue);

Status queue_enqueue(QUEUE hQueue, int value);
Status queue_service(QUEUE hQueue);
int queue_front(QUEUE hQueue, Status* pStatus);
Boolean queue_is_empty(QUEUE hQueue);
int queue_get_size(QUEUE hQueue);
void queue_output(QUEUE hQueue);