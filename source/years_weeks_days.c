#include <stdio.h>

int main(void)
{
	int days;
	printf("Enter number of days: ");
	scanf("%d", &days);
	
	printf("Years: %d\n", days / 365);
	days %= 365;
	printf("Weeks: %d\n", days / 7);
	days %= 7;
	printf("Days: %d\n", days);
	return 0;
}
