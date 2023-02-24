#include <stdio.h>

void print_binary(int n);

int main(int argc, char* argv[])
{
	printf("42 && 5 evaluates as %d\n", 42 && 5);
	printf("42 & 5 evaluates as %d\n", 42 & 5);
	printf("42 & 2 evaluates as %d\n", 42 & 2);

	printf("42 || 5 evaluates as %d\n", 42 || 5);
	printf("42 | 5 evaluates as %d\n", 42 | 5);

	print_binary(42);
	printf("\n");
	print_binary(47);

	return 0;
}

void print_binary(int n)
{
	if (n == 0)
		return;
	print_binary(n >> 1); // same as n/2
	printf("%d", n & 1 ); // same as n%2
}
