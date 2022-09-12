#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))
#define REMAINDER(y) ((y) % 4)
#define PRODUCT(x, y) (((x) * (y) > 100) ? 1 : 0)

int main(void)
{
	printf("Cube of x: %d\n", CUBE(5));
	printf("n %% 4 =  %d\n", REMAINDER(100));
	printf("If the priduct of x and y is less than 100, return 1, otherwise 0: %d\n", PRODUCT(100, 6));
	return 0;
}
