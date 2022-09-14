#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

bool number(int x);
void flush(void);

int main(void)
{
	char greeting[] = { "Congratulations!" };
	int num, i = 0;
	for(;;)
	{
		printf("Enter a number that is divible by 2: ");
		scanf("%d", &num);
		
		if(number(num) == true)
		{
			while(greeting[i] != '\0')
			{
				putchar(greeting[i++]);
				flush();
				sleep(1);
			}
			printf("\n");
			break;
		}
		else
		{
			printf("%d is not divible by 2!\n", num);
		}
	}
}

bool number(int x)
{
	return (x % 2 == 0) ? true : false;
}

void flush(void)
{
	fflush(stdout);
}
