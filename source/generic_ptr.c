#include <stdio.h>

int main(void)
{
	int x = 10;
	char c = 'A';
	void* ptr;
	
	ptr = &x;
	printf("x = %d\n", *(int*)ptr);
	ptr = &c;
	printf("c = %c\n", *(char*)ptr);
	return 0;
}
