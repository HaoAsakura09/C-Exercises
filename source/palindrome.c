#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 50

bool is_palindrome(char s[], int n);

int read_message(char s[], int n);

void print(char s[], int n);
int main(void)
{
 char msg[MAX_LEN];

 printf("Enter a message: ");
 int length = read_message(msg, MAX_LEN);

 if(is_palindrome(msg, length))
    printf("Palindrome\n");
 else
    printf("\nNot a palindrome");

    return 0;
}

int read_message(char s[], int n)
{
    int c, i = 0;
    while((c = getchar()) != '\n')
    {
        //convert to lowercase
        if('A' <= c && c <= 'Z')
            c = 'z' - 'Z' + c;
        if(i < n && c >= 'A' && c <= 'z')
        {
            s[i++] = c;
        }
    }

    return i;
}

bool is_palindrome(char s[], int n)
{
    int end = n - 1, i = 0;

    while(i <= n)
    {
        if(s[i++] != s[end--])
            return false;
    }
    return true;
}


