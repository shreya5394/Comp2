#include <stdio.h>
#include <stdlib.h>
#include "date.h"

struct date
{
	int day;
	int month;
	int year;
};

typedef struct date Date;

DATE date_init_default(void) {
	printf("Initializing data \n");

	DATE hDate;
	hDate = (Date*) malloc(sizeof(Date));
	if (hDate == NULL) {
		printf("malloc failed in date_init_default \n");
		return NULL;
	}
	return hDate;

}

void date_destroy(DATE hDate) {
	printf("Destroying date \n");
	Date* pDate = (Date*)hDate; //casting to the known type

	free(pDate);
	return;
}

void date_set_day(DATE hDate, int day) {
	Date* d = (Date*)hDate;
	d->day = day;
}
void date_set_month(DATE hDate, int month) {
	Date* d = (Date*)hDate;
	d->month = month;
}
void date_set_year(DATE hDate, int year) {
	Date* d = (Date*)hDate;
	d->year = year;
}

void date_output(DATE hDate) {
	Date* d = (Date*)hDate;
	printf("%d/%d/%d",d->day,d->month,d->year);
}



