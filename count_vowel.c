#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch;
	int num_vowel = 0;
	printf("Enter a snetence: ");
	ch = getchar();
	
	while(ch != '\n')
	{
		switch(toupper(ch))
		{
			case 'A': case 'E': case 'I': case 'U': case 'O': 
				num_vowel++; break;
		}
		ch = getchar();
	}
	
	printf("Your sentence contains %d vowel%c.\n", num_vowel,  (num_vowel > 1) ? 's' : '\0');
        return 0;
}
