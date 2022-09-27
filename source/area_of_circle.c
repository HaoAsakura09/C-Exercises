#include <stdio.h>

#define PI 3.14159

int main(void)
{
	double radius, area;
	
	printf("\nEnter the radius of the circle: ");
	scanf("%lf", &radius);
	
	area = PI * radius * radius;
	printf("Area: %.2f\n", area);
	
	return 0;
}
