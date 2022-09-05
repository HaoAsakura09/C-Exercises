#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 20

void read_input(char var [], int size);

bool is_valid(char *var);

int main(void)
{
    char var_name[MAX + 1];
    bool validation = false;

    while(validation != true)
    {
        read_input(var_name, MAX);
        validation = is_valid(var_name);

        if(validation == false)
            printf("Invalid variable name!\n");
    }

    printf("Variable is successfully created!\n");
    return 0;
}

bool is_valid(char *var)
{
    unsigned char *p = var;

    if((isspace(*p) || isdigit(*p) || !(isalpha(*p))))
        return false;

    p++; // Skip the first tested character

    // if this becomes false, the input is invalid!
    bool pass = true;

    while(*p != '\n')
    {
        if(isspace(*p))
            pass = false;

        switch(*p)
        {
            case '+': case '-': case '/': case '*':
            pass = false;
        }
        p++;
    }

    return pass;
}

void read_input(char var[], int size)
{
    int c, i = 0;
    while((c = getchar()) != '\n')
    {
        if(i < size)
            var[i] = c;
        i++;
    }

    var[i] = '\n';
}
