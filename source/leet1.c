#include <stdlib.h>
#include <stdio.h>

void sum(int arr[], int size, int target);

int main(void)
{
	typedef int Size;
	Size n_array = 10;
	int *arr = malloc(n_array * sizeof(arr[0]));
	int i = 0, target;
	char ch;
   	
	scanf("%c", &ch);
	
	while(ch != '\n')
	{
		if(i < n_array && ch != ' ')
			arr[i++] = atoi(&ch);
		scanf("%c", &ch);
	}
	
	printf("Enter taget: ");
	scanf("%d", &target);
	sum(arr, i, target);
	return 0;
}

void sum(int arr[], int size, int target)
{
	int i1, i2;
	
	for(int i = 0; i < size; i++)
		if(arr[i] == target)
		{
			printf("[%d]\n", i);
			return;
		}
   
   for(int i = 0; i < size; i++)
   {
   	if(arr[i] + arr[i + 1] == target)
   	{
   		i1 = i;
   		i2 = i + 1;
   		printf("[%d,%d]\n", i1, i2);
   		return;
   	}
   	else if(arr[i] + arr[size - 1] == target)
   	{
   		i1 = i;
   		i2 = size - 1 - i;
   		printf("[%d, %d]", i1, i2);
   	}
   }
}
