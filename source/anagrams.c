#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define LEN 20

bool anagrams(char str1[], char str2[]);
int read_line(char str1[], int length);

int main(void)
{
	char str1[LEN], str2[LEN];
	
	printf("Enter the first word: ");
	read_line(str1, LEN);
	printf("Enter the second word: ");
	read_line(str2, LEN);
	
	if(anagrams(str1, str2) == true)
		printf("%s and %s are anagrams.\n", str1, str2);
	else
		printf("%s and %s are not anagrams.\n", str1, str2);
	return 0;
}

int read_line(char str1[], int len)
{
	int ch, i = 0;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < len)
			str1[i++] = ch;
		ch = getchar();
	}
	str1[i] = '\0';
	return i;
}

bool anagrams(char str1[], char str2[])
{
	int i = 0;
	int s1[26] = { 0 }, s2[26] = { 0 };
    
   while(str1[i] != '\0')
   	++s1[(tolower(str1[i++])) - 'a'];
   	
  i = 0;
   while(str2[i] != '\0')
   	++s2[(tolower(str2[i++])) - 'a'];
   
   for(i = 0; i < 26; i++)
   {
   	if(s1[i] != s2[i])
   		return false;
   }
   return true;
}
