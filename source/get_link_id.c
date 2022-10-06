#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINK_LEN 50
char *get_id(char *link);

int read_line(char link[], int len);

int main(void)
{
	char yt_link[LINK_LEN], *p;
	
	read_line(yt_link, LINK_LEN);
	
	p = get_id(yt_link);
	
	printf("%s", p);
   free(p);
	return 0;
}

int read_line(char link[], int len)
{
	int i = 0, ch;
	while(isspace(ch = getchar()))
	 	;
	 while(ch != '\n' && ch != EOF)
	 {
	 	if(i < len)
	 		link[i++] = ch;
	 	ch = getchar();
	 }
	 link[i] = '\0';
	 return i;
}

char *get_id(char *link)
{
	
	char *p = link, *result;
	result = malloc(strlen(link) + 1);
	if(result == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	 
	 while(*p != '\0')
	 	p++;
   
   while(*p != '=' && *p != '/')
   	p--;
	strcpy(result, ++p);
	
	return result;
}
