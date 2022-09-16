#include <stdbool.h>
#include <stdio.h>

void sort_array(int a[], unsigned n);

int main(void)
{
	typedef unsigned  SIZE;
	
	SIZE length;
	
	printf("Enter number  of array elements to be sorted: ");
	scanf("%d", &length);
	
	int a[length];
	
	printf("Enter %d integers: ", length);
	for(int i = 0; i < length; i++)
		scanf("%d", &a[i]);
		
	sort_array(a, length);
	
	printf("Sorted array:");
	for(int i = 0; i < length; i++)
		printf(" %d", a[i]);
	return 0;
}

void sort_array(int a[], unsigned n)
{
    int temp;
    int start;
    
    for( start = 0; start < n - 1; start++)
    {
    	for(int current = start + 1; current < n; current++)
    	{
    		if(a[start] > a[current])
    		{
    			temp = a[current];
    			a[current] = a[start];
    			a[start] = temp;
    		}
    	}
    }
}
