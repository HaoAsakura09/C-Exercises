#include <stdio.h>

struct Time
{
	int hour;
	int minute;
	int second;
};

struct Time split_time(long total_seconds)
{
	struct Time time;
	
	if((total_seconds / 60 / 60) >= 1)
	{
		time.hour = total_seconds / 60 / 60;
		total_seconds -= time.hour * 60 * 60;
	}
	
  if((total_seconds / 60) >= 1)
	{
		time.minute = total_seconds / 60;
		total_seconds -= time.minute * 60;
	}
	
	if(time.second < 59)
		time.second = total_seconds;
	
	return time;
};

int main(void)
{
	struct Time time;
	
	time = split_time(16000);
	
	printf("Hour(s): %d, minute(s): %d, second(s): %d\n", time.hour, time.minute, time.second);
	return 0;
}
