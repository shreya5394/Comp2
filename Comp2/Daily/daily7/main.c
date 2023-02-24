/***************************************************
Program: Daily 7
Author: Shreya Mishra
Date: February 11th, 2023
Time spent: 5 hours
Purpose: The purpose of this program is to determine 
the number of strings of any length using the following choices:
a. It is an empty string.
b. If string A is correct and string B is correct then string AB is correct.
c. If A is correct then (A), [A] and {A} are all correct.
Is the length of the given string is correct, the output prints "yes", 
otherwise if you don't give the amount of strings then the output prints "no"
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "status.h"

Boolean check_string(void);  
void clear_keyboard_buffer(void);

int main(int argc, char* argv[]) {
    int checks;

    scanf("%d", &checks);
    clear_keyboard_buffer();

    for(int i = 0; i < checks; i++){ 
        if(check_string())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

Boolean check_string(void) { 
    char c;
    char top;

    Status status;
    Boolean outcome = TRUE;

    STACK hStack = stack_init_default();  

    if (hStack == NULL) {
        printf("failed to allocate stack obj\n");
        exit(1);
    }

    int noc = scanf("%c", &c); 
    while (noc != EOF && c != '\n') {
        if (stack_empty(hStack) && (c == ')' || c == ']' || c == '}')) {
            outcome = FALSE;
        }
        if (c == '(' || c == '[' || c == '{'){
            stack_push(hStack, c);
            //printf("Pushed: %c\n",c);
        }   
        else if (c == ')' && stack_top(hStack,&status) == '('){
            stack_pop(hStack);
            //printf("Popped: (\n");
        }
        else if (c == ']' && stack_top(hStack,&status) == '['){
            stack_pop(hStack);
            //printf("Popped: [\n");
        }
        else if (c == '}' && stack_top(hStack,&status) == '{'){
            stack_pop(hStack);
            //printf("Popped: {\n");
        }
        noc = scanf("%c", &c);
    }

    if (!stack_empty(hStack) )
        outcome = FALSE;

    stack_destroy(&hStack);
    return outcome;
}

void clear_keyboard_buffer(void) {
    char c;
    scanf("%c", &c);
    while (c != '\n'){
        scanf("%c", &c);
    }
}