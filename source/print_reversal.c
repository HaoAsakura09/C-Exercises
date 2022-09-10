#include <ctype.h>
#include <stdio.h>

#define MAX_LEN 50

int read_input(char s[], int n);
void print_reversal(char s[], int length);

int main(void)
{
    char s[MAX_LEN];
    int str_length;
    str_length = read_input(s, MAX_LEN);
    print_reversal(s, str_length);
    return 0;
}

int read_input(char s[], int n)
{
    printf("Enter a message: ");
    int i = 0, c;

    while((c = getchar()) != '\n')
    {

        if( i < n)
        {
          s[i++] = c;
        }
    }

    return i;
}

void print_reversal(char s[], int length)
{
    int i;
    printf("Reversal is: ");

    for(i = length - 1; i >= 0; i--)
        if(s[i] != '\n')
            printf("%c", s[i]);
}
