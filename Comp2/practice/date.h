#include <stdio.h>

typedef void* DATE;

DATE date_init_default(void);
void date_destroy(DATE hDate);

void date_set_day(DATE hDate, int day);
void date_set_month(DATE hDate, int month);
void date_set_year(DATE hDate, int year);

void date_output(DATE hDate);
