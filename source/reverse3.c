/* Reverses a series of numbers (pointer version) */

#include <stdio.h>

#define N 10

int main(void)
{
    int a[N], *p;
    
    printf("Enter %d numberes: ", N);
    for(p = a; p < a + N; p++)
        scanf("%d", p); // we don't use & on p because it is a pointer
    
    printf("In reverse order:");
    for(p = a + N - 1; p >= a; p--)
        printf(" %d", *p);
    printf("\n");
    
    return 0;
}

