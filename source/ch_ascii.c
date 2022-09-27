#include <stdio.h>

int main(void)
{
	char ch; 
	int n;
	
	printf("Letter\tASCII\n");
	while((ch = getchar()) != '*')
	{
		if(ch >= 'a' && ch <= 'z')
		{
			n = ch - 'a' + 'A';
			printf("%c\t%d\n", ch - 'a' + 'A', n);
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			n = ch - 'A' + 'a';
			printf("%c\t%d\n", ch - 'A' + 'a', n);
		}
		getchar();
	}
	
	return 0;
}
