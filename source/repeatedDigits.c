#include <stdio.h>

#define NUM_DIGIT 10

int main(void)
{
	int occurences[NUM_DIGIT] = { 0 }, digit = 0;
	
	long num;
	
	printf("Enter a number: ");
	scanf("%ld", &num);
	
	while(num > 0)
	{
		// gets the last digit 
		digit = num % 10;
		// use the digit varoable for subscripting the array
		// Increments the value when digit is found
		++occurences[digit];
		// Removes the last digit
		num /= 10;
	}
	
	printf("Repeated digit(s):");
	for(int i = 0; i < NUM_DIGIT; i++)
	{
		// If the array tha contains a value greater than 1
		// It means the digit apeared more than 1
		// print out the index number
		if(occurences[i] > 1)
			printf(" %d", i);
		
	}
	return 0;
}
