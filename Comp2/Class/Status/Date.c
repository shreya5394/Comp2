#include <stdio.h>
#include "Date.h"

struct date
{
	int day;
	int month;
	int year;
};

typedef struct date Date; //known type


DATE date_init_default(void)
{
	DATE hDate;
	printf("date_init_default \n");

	hDate = (Date*) malloc(sizeof(Date));
	if (hDate == NULL)
	{
		printf("error in date_init_default\n");
	}
	return hDate;
}

void date_destroy(DATE *phDate)
{
	Date* pDate = (Date*) *phDate; // casting to the known type 
	free(pDate);
	*phDate = NULL;

	printf("date destroy  \n");
}

void date_output(DATE hDate)
{
	Date* pDate = (DATE*) hDate;
	printf("%d/%d/%d", pDate->month, pDate->day, pDate->year);
}



void date_set_day(DATE hDate, int day)
{
	Date* pDate = (Date*)hDate; // casting to the known type 
	pDate->day = day;
}

Status date_set_month(DATE hDate, int month)
{
	if (month < 1 || month > 12)
	{
		return FAILURE;
	}
	Date* pDate = (Date*)hDate; // casting to the known type 
	pDate->month = month;
	return SUCCESS;
}


void date_set_year(DATE hDate, int year)
{
	Date* pDate = (Date*)hDate; // casting to the known type 
	pDate->year = year;
	//(*pDate).year = year;
}


