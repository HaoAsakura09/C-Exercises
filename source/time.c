/* My Solution to C: A Modern Approach project */
#include <stdio.h>

int main(void)
{
    int hour, minute;
    printf("Enter a 24-hour time: ");
    scanf("%2d:%2d", &hour, &minute);

    if(hour <= 11)
        printf("Equivalent 12-hour time: %d:%.2d AM\n", (hour == 0) ? hour : hour, minute);
    else
    {
        hour = hour - 12;
        printf("Equivalent 12-hour time: %d:%d PM\n", hour, minute);
    }
    return 0;
}
