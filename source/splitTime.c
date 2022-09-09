#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void)
{
	int total_sec, hr, min, sec;
	printf("Enter total seconds: ");
	scanf("%d", &total_sec);
	
	split_time(total_sec, &hr, &min, &sec);
	
	printf("Number of hour%c: %d\n", (hr > 1) ? 's' : ' ', hr);
	printf("Number of minute%c: %d\n", (min > 1) ? 's' : ' ', min);
	printf("Number of second%c: %d\n", (sec > 1) ? 's' : ' ', sec);
	return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
	int num_hr = 0, num_min = 0, num_sec = 0;
	
	if((total_sec / 60 / 60) >= 1)
	{
		num_hr = total_sec / 60 / 60;
		total_sec -= num_hr * 60 * 60;
	}
	
	if((total_sec / 60) >= 1)
	{
		num_min = total_sec / 60;
		total_sec -= num_min * 60;
	}
	
	if((total_sec < 60))
	{
		num_sec = total_sec;
	}
	
	*hr = num_hr;
	*min = num_min;
	*sec = num_sec;
}

