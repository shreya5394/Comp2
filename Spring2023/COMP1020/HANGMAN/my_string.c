#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

struct my_string{
    int size;
    int capacity;
    char* data;
};

typedef struct my_string My_string;

MY_STRING my_string_init_default(void){
    My_string* string = (My_string*)malloc(sizeof(My_string));
    if (string !=  NULL){
        string->capacity = 7; 
        string->size = 0; 
        string->data =  (char*)malloc(sizeof(char)*string->capacity);
    if (string->data ==  NULL){
         free(string);
        return NULL;
        }
    }
    return string;
}

MY_STRING my_string_init_c_string(const char* c_string){
    My_string* string = (My_string*)malloc(sizeof(My_string));

    if (string != NULL){
        string->size = 0;
        while(c_string[string->size] != '\0'){
            string->size++;
        }
        string->capacity = string->size+1;
        string->data = (char*)malloc(sizeof(char)*string->capacity);
        if (string->data == NULL){
            free(string);
            return NULL;
        }

        for(int i = 0; i<string->size; i++){
            string->data[i] = c_string[i];
        }
    }
    return string;
}

void my_string_destroy(MY_STRING* phMy_string)
{
    My_string* string = (My_string*)*phMy_string;
    free(string->data);
    free(string);

    *phMy_string = NULL;
}

int my_string_get_capacity(MY_STRING hMy_string){
    My_string* string = (My_string*)hMy_string;
    return string->capacity;
}

int my_string_get_size(MY_STRING hMy_string){
    My_string* string = (My_string*)hMy_string;
    return string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
    My_string* stringL = (My_string*)hLeft_string;
    My_string* stringR = (My_string*)hRight_string;

    char* sL = stringL->data;
    char* sR = stringR->data;

    int i;
    for (i = 0; sL[i] != '\0' && sR[i] != '\0'; i++) {
        if (sL[i] > sR[i]) 
            return 1;
        else if (sR[i] > sL[i]) 
            return -1;
    }

    // comparing length of two strings
    if (sL[i] != '\0') 
        return 1;
    else if (sR[i] != '\0') 
        return -1;
    else 
       return 0;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){   
    My_string* string = (My_string*)hMy_string;
    if (string == NULL || fp == NULL)
        return FAILURE;
        
    string->size=0;
    int size=0;
    char c;
    while (fscanf(fp,"%c",&c) == 1) {
        if (c == ' ')
            break;
        if (string->size >= string->capacity){
            char *temp = (char*)malloc(sizeof(char)*string->capacity*2);
            if (temp == NULL){
                free(string);
                return FAILURE;
            }  
            for(int i = 0; i<string->size; i++){
                temp[i] = string->data[i];
            }
            string->data = temp;
            string->capacity *=2;
        }
        string->data[size] = c;
        string->size++;
        size++;
    }
    //printf("%s \n", string->data);
    if(string->size >= 1)
        return SUCCESS;
    else
        return FAILURE;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp){
    My_string* string = (My_string*)hMy_string;
    int size = string->size;
    //printf("%s %d", string->data, string->size);
    if (size == 29){
        int noc = fprintf(fp,"%s",string->data);
        if(noc == 1)
            return SUCCESS;
        else
            return FAILURE;
    }
    return SUCCESS;   
}


/*
Status my_string_push_back(MY_STRING hMy_string, char item){

}

Status my_string_pop_back(MY_STRING hMy_string){

}

char* my_string_at(MY_STRING hMy_string, int index){

}

char* my_string_c_str(MY_STRING hMy_string){

}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){

}

Boolean my_string_empty(MY_STRING hMy_string){

}

*/

