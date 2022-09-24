#include <stdio.h>

#define ECHO(n) (scanf("%d", &n), printf("Age: %d\n", n))

int main(void)
{
	int age;
	
	printf("Enter your age: ");
	ECHO(age);
	return 0;
}
