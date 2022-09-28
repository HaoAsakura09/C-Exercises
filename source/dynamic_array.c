#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t aSize = 10;
	int *a = calloc(aSize, sizeof(int));
	
	if(a == NULL)
	{
		printf("Malloc failed to alocate memory for a.\n");
		return 0;
	}
	
  int e, i = 0;
  printf("Enter %lu integers: ", aSize);
  scanf("%d", &e);
  while(e != 0)
  {
  	if(i < aSize)
  		a[i] = e;
  	 else
  	 {
  	 	printf("Allocating more space for a.\n");
  	 	aSize *= 2;
  	 	a = realloc(a, aSize * sizeof(int));
  	 	if(a == NULL)
  	 	{
  	 		printf("Can't allocate more space.\n");
  	 		return 0;
  	 	}
  	 }
  	 scanf("%d", &e);
  	 i++;
  }
  
  printf("You entered:");
  int z;
  for(z = 0; z < i; z++)
  	printf(" %d", a[z]);
	return 0;
}
