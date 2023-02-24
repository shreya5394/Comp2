#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

/*
//LAB #2 
int main(int argc, char* argv[])
{
    MY_STRING hMy_string = NULL;
    //hMy_string = my_string_init_default();
    hMy_string = my_string_init_c_string("hi");

    printf("size=%d \n", my_string_get_size(hMy_string));
    printf("capacity=%d \n", my_string_get_capacity(hMy_string));

    MY_STRING hLeft = my_string_init_c_string("hill");
    MY_STRING hRight = my_string_init_c_string("hi");
    printf("compare=%d \n", my_string_compare(hLeft,hRight));
    my_string_destroy(&hLeft);
    my_string_destroy(&hRight);

    my_string_destroy(&hMy_string);
    return 0;
}
*/


//LAB #3 
int main(int argc, char* argv[])
{
    MY_STRING hMy_string = NULL;
    FILE* fp;

    hMy_string = my_string_init_default();
    fp = fopen("simple.txt", "r");

    while(my_string_extraction(hMy_string, fp)){
        my_string_insertion(hMy_string, stdout);
        printf("\n");
        //if(fgetc(fp)== ' '){
            //printf("Found a space after the string\n");
        //}
    }

    my_string_destroy(&hMy_string);
    fclose(fp);
    return 0;
}
