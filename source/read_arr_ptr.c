#include <conio.h>
#include <stdio.h>

#define N 10

int main(void)
{
	int arr[N], *p;
	
	printf("Enter %d elements into array:\n", N);
	for(p = &arr[0]; p < &arr[N]; p++)
		scanf("%d", p);
	
	clrscr();
	
	printf("Entered:");
	for(p = &arr[0]; p < &arr[N]; p++)
		printf(" %d", *p);
	return 0;
}
