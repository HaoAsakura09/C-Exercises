#include <stdio.h>

int main(void)
{
	int a, b, c, max, s_max, t_max;
	printf("Enter three integers: ");
	scanf("%d %d %d", &a, &b, &c);
	
	if(a > b && a > c)
		max = a;
	else if(b > a && b > c)
		max = b;
	else
		max = c;
		
	if(a < max)
		s_max = a;
   if (b < max)
		s_max = b;
	if(c < max)
		s_max = c;
	
	if(a < s_max)
		t_max = a;
  if(b < s_max)
		t_max = b;
   if(c < s_max)
		t_max = c;
	
	printf("1st Number = %d, 2nd Number = %d, 3rd Number = %d\n", t_max, s_max, max);
	return 0;
}
