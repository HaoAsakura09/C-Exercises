#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 50

bool is_palindrome(char s[], int n);

int read_message(char s[], int n);

int main(void)
{
 char msg[MAX_LEN];

 printf("Enter a message: ");
 int length = read_message(msg, MAX_LEN);

 if(is_palindrome(msg, length))
    printf("Palindrome\n");
 else
    printf("Not a palindrome");

    return 0;
}

int read_message(char s[], int n)
{
    int c, i = 0;
    char *p = &s[0];
    while((c = getchar()) != '\n')
    {
        //convert to lower
        if('A' <= c && c <= 'Z')
            c = 'z' - 'Z' + c;
        if(i < n && c >= 'A' && c <= 'z')
        {
            *p++ = c;
            i++;
        }
    }

    return i;
}

bool is_palindrome(char s[], int n)
{
    char *end = &s[n - 1], *start = &s[0];

    while(*start++ != *end--)
        return false;
    return true;
}


