#include <stdio.h>

void print_date(char *month, int day, int year);

int main(void)
{
	char *month[] = { "", "January", "February", "March", "April",
													"May", "June", "July", "August",
													"September", "October", "Novber",
													"December" };
	int day, mm, year;
	printf("Enter a date (mm/dd/yy): ");
	scanf("%d/%d/%d", &mm, &day, &year);
	
	print_date(month[mm], day, year);
	return 0;
}

void print_date(char *month, int day, int year)
{
	printf("You entered the date %s, %d, %d\n", month, day, year);
}
