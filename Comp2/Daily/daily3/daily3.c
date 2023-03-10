/***********************************************************
Author: Shreya Mishra
Date: January 24th, 2023
Effort: 2 hours 
Purpose: Bitwise or | and &
to set and check the bit of a number
***********************************************************/
#include <stdio.h>

void set_flag(int* pFlag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);
int main(int argc, char* argv[])
{
	int flag_holder = 0;
	int i;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

void set_flag(int* pFlag_holder, int flag_position) {
	int i = 1 << flag_position;
	*pFlag_holder = *pFlag_holder | i;
}

int check_flag(int flag_holder, int flag_position) {
	int i = 1 << flag_position;
	flag_holder = i & flag_holder;
	if (flag_holder == i)
		return 1;
	else
		return 0;
}