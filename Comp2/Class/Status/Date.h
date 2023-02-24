#include "Status.h"

typedef void* DATE;

DATE date_init_default(void);
void date_destroy(DATE* phDate);

void date_set_day(DATE hDate, int day);
Status date_set_month(DATE hDate, int month);
void date_set_year(DATE hDate, int year);

void date_output(DATE hDate);
