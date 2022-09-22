#include <stdio.h>

#define NUM_SCORE 5

void read_score(int *score, int size);
void total_score(int *score, int size, int *total_score);
void get_average(int *score, int size, double *average);
void high_low(int *score, int size, int *highest, int *lowest);
void print_result(int *total_score, double *average, int *highest, int *lowest);

int main(void)
{
	int scores[NUM_SCORE], total, highest, lowest;
	double average;
	printf("Enter %d scores: ", NUM_SCORE);
	read_score(scores, NUM_SCORE);
	
	total_score(scores, NUM_SCORE, &total);
	
	get_average(scores, NUM_SCORE, &average);
	
	high_low(scores, NUM_SCORE, &highest, &lowest);
	
	print_result(&total, &average, &highest, &lowest);
	return 0;
}

void read_score(int *score, int size)
{
	int *p;
	for(p = score; p < score + size; p++)
		scanf("%d", p);
}

void total_score(int *score, int size, int *total_score)
{
	int *p;
	*total_score = 0;
	for(p = score; p < score + size; p++)
		*total_score += *p;
}

void get_average(int *score, int size, double *average)
{
	int *p;
	*average = 0;
	for(p = score; p < score + size; p++)
		*average += *p;
	
	*average /= size;
}

void high_low(int *score, int size, int *highest, int *lowest)
{
	int *p;
	*highest = *lowest = *score;
	for(p = score; p < score + size; p++)
		if(*p > *highest)
			*highest = *p;
		else if(*p < *lowest)
			*lowest = *p;	
}

void print_result(int *total_score, double *average, int *highest, int *lowest)
{
	printf("Your total score: %d\n", *total_score);
	printf("Your average: %.2f\n", *average);
	printf("You highest score: %d\n", *highest);
	printf("Your lowest score: %d\n", *lowest);
}
