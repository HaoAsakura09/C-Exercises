#include <ctype.h>
#include <stdio.h>

#define MSG_LEN 30

int read_line(char str[], int len);

int main(void)
{
	char msg[MSG_LEN];
	read_line(msg, MSG_LEN);
	
	printf("%s\n", msg);
	return 0;
}

int read_line(char str[], int len)
{
	int ch, i = 0;
	while(isspace(ch = tolower( getchar())))
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < len && !isspace(ch))
			str[i++] = tolower(('z' - (ch - 'a')));
		else if(isspace(ch))
			str[i++] = ' ';
			
		ch = tolower(getchar());
	}
	str[i] = '\0';
  return i;
}
