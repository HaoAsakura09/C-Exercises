#include <stdio.h>

#define MAX_LEN 50

int read_line(char str[], int n);

int main(void)
{
    char str[50 + 1];
    printf("Enter a random message: ");
    read_line(str, MAX_LEN);

    printf("Your message: %s\n", str);
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n')
    {
        if(i < n)
            str[i++] = ch;
    }
    str[i] = '\0';      /* terminates string */
    return i;           /* number of characters stored */
}
