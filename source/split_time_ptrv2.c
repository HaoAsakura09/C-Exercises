#include <stdio.h>

struct time
{
	int hour;
	int minute;
	int second;
};

struct time split_time(long total_seconds)
{
	struct time get_time;
	get_time.hour = total_seconds / 3600;
	total_seconds %= 3600;
	get_time.minute = total_seconds / 60;
	total_seconds %= 60;
	get_time.second = total_seconds;
	
	return get_time;
};

int main(void)
{
	struct time show_time;
	long seconds;
	printf("Enter number of seconds: ");
	scanf("%ld", &seconds);
	show_time = split_time(seconds);
	
	printf("Hour%c: %d, ", (show_time.hour > 1) ? 's' : '\0', show_time.hour);
	printf("Minute%c: %d, ", (show_time.minute > 1) ? 's' : '\0', show_time.minute);
	printf("Second%c: %d\n", (show_time.second > 1) ? 's' : '\0', show_time.second);
	return 0;
}
