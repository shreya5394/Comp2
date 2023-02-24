#include "stack.h"

typedef void* STACK;

STACK stack_init_default();
void stack_destroy(STACK* phStack);

Status stack_push(STACK hStack, int value);
Status stack_pop(STACK hStack);
int stack_top(STACK hStack, Status* pStatus);
Boolean stack_is_empty(STACK hStack);