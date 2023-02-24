#include <stdio.h>
char* reverse(char* str);
/*
Author: Shreya Mishra
Date: January 19th, 2023
Purpose: Reverse a string in place.
Time Spent: I spent 1-2 hours working on my daily
*/


int main(int argc, char* argv[]){
    char s[40] = "My Little Pony!";
    char* r = reverse(s);
    printf("%s", r);
    return 0;
}

char* reverse(char* str) {

    char* s = str;
    if (s == NULL)
        return NULL;
    if (*s == '\0')
        return '\0';
    int len = 0;

    while (*s != '\0') {
        len = len + 1;
        s++;
    }
    // Reverse the c-string in place
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

