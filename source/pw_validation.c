#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define PW_LEN 50
int main() {
    char password[PW_LEN];
    int ch, i = 0, n_num = 0, s_char = 0;
    //printf("Enter password: ");
    while(isspace(ch = getchar()))
        ;
    while(ch != '\n' && ch != EOF)
    {
        if(i < PW_LEN)
          password[i++] = ch;
        ch = getchar();
        
        if(isdigit(ch))
            n_num++;
        if(ch == '!' || 
           ch == '@' ||
           ch == '#' ||
           ch == '$' ||
           ch == '%' ||
           ch == '&' ||
           ch == '*')
           s_char++;
    }
    
    password[i] = '\0';
    
    if(strlen(password) > 7 &&
       n_num >= 1 && s_char >= 1)
       printf("Strong");
    else
       printf("Weak");
    return 0;
}
