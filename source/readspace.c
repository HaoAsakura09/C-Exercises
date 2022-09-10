#include <stdio.h>

#define MAX_LEN 50

int count_spaces(const char s[]);

int read_line(char s[], int n);

int main(void)
{
    char message[MAX_LEN + 1];
    int num_length, num_space;
    printf("\nThis program counts spaces and length in a string\n");
    printf("Enter your message: ");
    num_length = read_line(message, MAX_LEN);
    printf("\nYour messsage length: %d\n", num_length);
    num_space = count_spaces(message);
    printf("Spaces in your message: %d\n", num_space);

    return 0;
}

int read_line(char s[], int n)
{
    int i = 0, c;

    while((c = getchar()) != '\n')
        if(i < n)
            s[i++] = c;
    return i;
}

int count_spaces(const char s[])
{
    int count = 0, i;

    for(i = 0; s[i] != '\0'; i++)
        if(s[i] == ' ')
            count++;
    return count;
}
