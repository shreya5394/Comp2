#include <stdio.h>
#include <stdlib.h>

#include "Date.h"

int main()
{
	DATE hToday;

	hToday = date_init_default();
	if (hToday == NULL)
	{
		exit(1);
	}

	date_set_day(hToday, 23);
	if (!date_set_month(hToday, 23))
	{
		printf("error setting month in date\n");
		date_set_month(hToday, 1);
	}
	date_set_year(hToday,2023);

	date_output(hToday);
	printf("\n");


	date_destroy(&hToday);
	//hToday = NULL;


	return 0;
}