#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void)
{
	long total_sec;
	int hour, minute, second;
	printf("Enter number of second(s): ");
	scanf("%ld", &total_sec);
	
	split_time(total_sec, &hour, &minute, &second);
	
	printf("Hour: %d, Minutes: %d, Seconds: %d\n", hour, minute, second);
	return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
	if((total_sec / 60 / 60) >= 1)
	{
		*hr = total_sec / 60 / 60;
		  total_sec -= *hr * 60 * 60;
	}
	else
		*hr = 0;
	
	 if((total_sec / 60) >= 1)
	 {
	 	*min = total_sec / 60; 
	 	total_sec -= *min * 60;
	 }
	 else
	 	*hr = 0;
	 
	 if( total_sec < 60)
	 	*sec = total_sec;
	 else
	 	*sec = 0;
}
