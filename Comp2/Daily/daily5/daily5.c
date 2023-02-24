/***********************************************************
Author: Shreya Mishra
Date: January 31st, 2023
Effort: 2 hours
Purpose: Experiment more on
Bitwise or | and & to set and check the bit of a numbers.
Have the array of bits and displays one integer per line using the
display_flags_as_array function.
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 };//Set the first integer to zero and all others to zero by default.

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    display_flags(flag_holder, 5);
    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);

    display_flags(flag_holder, 5);
    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position) {
    int bit_set = flag_position % 32;
    int row = flag_position / 32;
    //printf("Position: %d, Row: %d \n", bit_set,row);

    int i = 1 << bit_set;
    flag_holder[row] = flag_holder[row] | i;
}

void unset_flag(unsigned int flag_holder[], int flag_position) {
    int bit_set = flag_position % 32;
    flag_position /= 32;
    int i = 1 << bit_set;

    flag_holder[flag_position] &= ~(1 << bit_set);
}

int check_flag(unsigned int flag_holder[], int flag_position) {
    int bit_set = flag_position % 32;
    flag_position /= 32;

    return (flag_holder[flag_position] >> bit_set) & 1;
}

void display_flags_as_array(unsigned int flag_holder) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", check_flag(&flag_holder, i));
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void display_flags(unsigned int flag_holder[], int size) {
    for (int i = 0; i < size;i++) {
        display_flags_as_array(flag_holder[i]);
    }
}
