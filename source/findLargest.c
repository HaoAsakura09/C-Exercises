#include <stdio.h>

#define N 10

int *find_largest(int a[], int n);
void print_largest(int *largest);
void read_input(int a[], int n);

int main(void)
{
	int b[N], *largest;
	read_input(b, N);
	largest = find_largest(b, N);
	print_largest(largest);
}

void read_input(int a[], int n)
{
	int i;
	printf("Enter %d integers: ", n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

void print_largest(int *largest)
{
	printf("Largest: %d\n", *largest);
}

int *find_largest(int a[], int n)
{
	int *p = &a[0], i;
	
	for(i = 0; i < n; i++)
	{
		if(a[i] > *p)
			p = &a[i];
	}
	
	return p;
}
