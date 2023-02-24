#include <stdio.h>
#include "date.h"


int main()
{
	DATE hToday;

	hToday = date_init_default();

	date_set_day(hToday, 23);
	date_set_month(hToday, 1);
	date_set_year(hToday, 2023);

	date_output(hToday);

	date_destroy(hToday);

	return 0;
}

