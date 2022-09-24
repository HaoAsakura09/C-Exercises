#include <stdio.h>

#define GENERIC_MAX(type)       \
type type##_max(type x, type y)  \
{ 																	 	 \
	return x > y ? x : y;								\
}																			\

GENERIC_MAX(int);
int main(void)
{
	printf("%d", int_max(5, 6));
	return 0;
}
