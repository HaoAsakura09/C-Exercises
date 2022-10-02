#include <stdio.h>

#define N1 10
#define N2 10
int main(void)
{
	int arr1[N1], arr2[N2], arr3[N1 + N2];

	// reads and assigns values to array1
	printf("Enter %d elements into array 1:\n", N1);
	for (int i = 0; i < N1; i++)
	{
		printf("Element-%d: ", i);
		scanf("%d", &arr1[i]);
	}

	// reads and assigns values to array 2
	printf("Enter %d elements into array 2:\n", N2);
	for (int i = 0; i < N2; i++)
	{
		printf("Element-%d: ", i);
		scanf("%d", &arr2[i]);
	}
	
	int j = 0;
	// merge array 1 and array 2
	for (int i = 0; i < N1 + N2; i++)
	{
		if (i < N1)
			arr3[i] = arr1[i];
		else
		{
			arr3[i] = arr2[j++];
		}
	}

  
  // sort in descending order
	for (int i = 0; i < N1 + N2 - 1; i++)
		for(int j = 0; j < N1 + N2; j++)
			{
				int temp = 0;
			   if(arr3[j + 1] > arr3[j])
			   {
			   	temp = arr3[j];
			   	arr3[j] = arr3[j + 1];
			   	arr3[j + 1] = temp;
			   }
			}
   
   printf("The merge array in descending order is: \n");
   for(int i = 0; i < N1 + N2; i++)
   	printf("%d ", arr3[i]);
   
	return 0;
}
