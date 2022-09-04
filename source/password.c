#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 20

int read_input(char pw[], int size);

bool is_valid(char pw[], int size);

int main(void)
{
    bool valid = false;
    int length = 0, retry_count = 0;

    char password[MAX + 1];
    printf("If you want to get into heaven. Please provide a valid password!\n");

    while(valid != true)
    {
       retry_count++;

       printf("Enter your password: ");
       length = read_input(password, MAX);
       valid = is_valid(password, length);

       if(valid == false)
        printf("Hint: Must contain uppercase, special symbol and greater than 8!\n");

       switch(retry_count)
       {
           case 2: printf("Read the hint!\n");
                   break;
           case 3: printf("You didn't read the hint!\n");
                   break;
           case 4: printf("Still didn't get it?\n");
                   break;
           case 5: printf("You are running out of time!\n");
                   break;
           default: if(retry_count > 5) printf("I'm out of this!\n");
                   break;
       }

       printf("\n");
    }

    if(retry_count == 1)
        printf("Welcome to heaven! Do not disturb, Jesas. He's writing code right now!\n");
        printf("Maybe you can help him? :)\n");
    else
        printf("Welcome to hell! Seytan will teach you English!\n");

    return 0;
}
int read_input(char pw[], int size)
{
    int c, i = 0;

    while(isspace(c = getchar())) // discards space
        ;

    while((c = getchar()) != '\n')
    {
        if(i < size && !isspace(c))
            pw[i] = c;
        i++;
    }

    pw[i] = '\0';
    return i;
}

bool is_valid(char pw[], int size)
{
    bool is_valid, has_upper, has_special_symbol, valid_length;

    is_valid = has_upper = has_special_symbol = valid_length = false;

    if(size > 8)
        valid_length = true;

    for(int i = 0; i < size; i++)
    {
        if((pw[i] < 'a') && (isalpha(pw[i])))
            has_upper = true;

        if(!(isalpha(pw[i]))) // is not alphabetic
            has_special_symbol = true;
    }

    return (has_upper && has_special_symbol && valid_length) ? true : false;
}
