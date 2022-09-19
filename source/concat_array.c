#include <stdio.h>

#define ARR1_LEN 10
#define ARR2_LEN 10
#define CON_SIZE (ARR1_LEN + ARR2_LEN)

void concat_arr(int m, int n, int arr1[m], int arr2[n], int concat_arr[m + n]);

void read_arr(int m, int arr[m]);

int main(void)
{
	int arr1[ARR1_LEN], arr2[ARR2_LEN], concat_array[CON_SIZE];
	
	printf("Enter %d integers for array 1: ", ARR1_LEN);
	read_arr(ARR1_LEN, arr1);
	printf("Enter %d integers for array 2: ", ARR2_LEN);
	read_arr(ARR2_LEN, arr2);
	
	concat_arr(ARR1_LEN, ARR2_LEN, arr1, arr2, concat_array);
	
	printf("Here's your concatenated array:");
	for(int i = 0; i < CON_SIZE; i++)
		printf(" %d", concat_array[i]);
	return 0;
}

void read_arr(int m, int arr[m])
{
	for(int i = 0; i < m; i++)
		scanf("%d", &arr[i]);
}

void concat_arr(int m, int n, int arr1[m], int arr2[n], int concat_arr[m + n])
{
	int i, y = 0;
	for(i = 0; i < m; i++)
		concat_arr[i] = arr1[i];
	
	for(; i < (m + n); y++, i++)
		concat_arr[i] = arr2[y];
}
