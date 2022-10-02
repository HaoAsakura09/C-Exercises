#include <stdio.h>

int main(void)
{
	int* z, m = 10, n, o;
	z = &m;
	
	printf("z stores the address of m = %p\n", z);
	printf("*z stores the value of m = %d\n", *z);
	printf("&m is the address of m = %p\n", &m);
	printf("&n stores the value of n = %p\n", &n);
	printf("&o stores the value of o = %p\n", &o);
	printf("&z stores the value of z = %p\n", &z);
}
