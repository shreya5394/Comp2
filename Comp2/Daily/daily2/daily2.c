/***********************************************************
Author: Shreya Mishra
Date: February 1st, 2023
Effort: 15 minutes
Purpose: Practice left shift operator.
After 32 shifts, the number is reduced to zero.
Using unsigned int and %u helped to demonstrate this.
***********************************************************/

#include <stdio.h>

int main(int argc, char* argv[]) {
	unsigned int x = 1;

	for (int i = 0; x != 0; i++) {
		printf("%d: %u \n", i, x);
		x = x << 1;
	}
	return 0;
}