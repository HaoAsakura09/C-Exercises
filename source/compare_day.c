#include <stdio.h>

struct date
{
	int month;
	int day;
	int year;
};

int compare_dates(struct date d1, struct date d2);
int day_of_year(struct date d);

int main(void)
{
	return 0;
}

int day_of_year(struct date d)
{
	int days = 0, i;
	enum month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER, NUM_MONTHS };
	
	int num_days[NUM_MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if(d.month >= 1 && ((d.year % 4 == 0  && d.year % 100 != 0) || d.year % 400 == 0))
	++num_days[FEBRUARY];
	
	for(i = 0; i < NUM_MONTHS; i++)
		days += num_days[i];

	return days;
}

int compare_dates(struct date d1, struct date d2)
{
	int day1, day2;
	day1 = day_of_year(d1);
	day2 = day_of_year(d2);
	
	if(day1 < day2)
		return -1;
	else if(day1 > day2)
		return 1;
	else 
		return 0;
}
