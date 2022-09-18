#include <stdio.h>

int main(void)
{
	int a, b, c, d, min, max;
	printf("Enter four integers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	if(a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	
	if(c > max)
		max = c;
   if(d > max)
		max = d;
	
	(c < min) ? (min = c) : (d < min) ? (min = d) : min;
	
   printf("Largest: %d\n", max);
   printf("Smallest: %d\n", min);
	return 0;
}
