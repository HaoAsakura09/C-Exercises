#include <stdio.h>

#define MAX_LEN 50

int read_message(char *s, int len);
void print_message(char *s, int len);

int main(void)
{
    char msg[MAX_LEN];
    int length;

    printf("Enter a message: ");
    length = read_message(msg, MAX_LEN);
    printf("Reversal is: ");
    print_message(msg, length);
}

int read_message(char *s, int len)
{
    char *p = s;
    int i = 0, c;

    while((c = getchar()) != '\n')
    {
        if(i < len)
        {
            *p++ = c;
            i++;
        }

    }
    return i;
}

void print_message(char *s, int len)
{
    char *p = s + len - 1;
    while(p >= s)
    {
        printf("%c", *p);
        p--;
    }
}
