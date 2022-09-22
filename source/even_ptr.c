#include <stdio.h>

#define ARR_LEN 100

void print_even(int *arr, int size);
void arr_num(int *arr, int size);

int main(void)
{
	int arr[ARR_LEN];
	arr_num(arr, ARR_LEN);
	print_even(arr, ARR_LEN);
	return 0;
}

void arr_num(int *arr, int size)
{
	int *p;
	int i = 0;
	for(p = arr; p < arr + size; p++)
		*p = i++;
}

void print_even(int *arr, int size)
{
	int *p;
	for(p = arr; p < arr + size; p++)
	{
		printf(" %d", *p++);
	}
}
