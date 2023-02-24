#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node Node;
struct node {
    char data;
    Node* next;
};

struct stack {
    Node* head;
};
typedef struct stack Stack; 

STACK stack_init_default(void) {
    Stack* pStack = (Stack*)malloc(sizeof(Stack)); 

    if (pStack != NULL) {
        pStack->head = NULL;  
    }
    return (STACK)pStack; 
}

Status stack_push(STACK hStack, char value) {
    Stack* pStack = (Stack*)hStack;
    Node* temp = (Node*)malloc(sizeof(Node));  

    if (temp != NULL) {
        temp->data = value; 
        temp->next = pStack->head;   
        pStack->head = temp;
    }
    else{
        printf("Couldn't allocate new node\n");
        return FAILURE;
    }

    return SUCCESS;
}

Status stack_pop(STACK hStack) {
    if (stack_empty(hStack)) {
        return FAILURE; 
    }
    Stack* pStack = (Stack*)hStack;
    Node* temp = pStack->head; 
    pStack->head = pStack->head->next; 
    free(temp);
    return SUCCESS; 

}

char stack_top(STACK hStack, Status* pStatus) {

    Stack* pStack = (Stack*)hStack; 

    if (pStack->head != NULL) { 
        return pStack->head->data;     
    }
    else {
        return -62;
    }

} 

Boolean stack_empty(STACK hStack) {

    Stack* pStack = (Stack*)hStack; 

    if (pStack->head != NULL) {
        return FALSE;
    }
    else {
        return TRUE; 
    }

}

void stack_destroy(STACK* phStack) {
    Stack* pStack = (Stack*)*phStack;
    Node* pNode = pStack->head; 
    while (pNode != NULL) {
        Node* temp = pNode;
        pNode = pNode->next; 
        free(temp); 
    }
    free(pStack); 
    *phStack = NULL;
}