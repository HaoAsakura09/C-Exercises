#include <stdio.h>

int main(void)
{
	int days;
	printf("Enter number of days: ");
	scanf("%d", &days);
	
	printf("Days: %d\n", days / 365);
	days %= 365;
	printf("Months: %d\n", days / 30);
	days %= 30;
	printf("Days: %d\n", days);
	return 0;
}
