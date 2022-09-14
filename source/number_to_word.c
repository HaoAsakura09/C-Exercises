#include <stdio.h>


void num_to_word(int n);
void ten(int n);
void ten1(int n);
void ten2(int n);
void hundred(int n);

int main(void)
{
	for(int i = 1; i <= 999; i++)
	{
		num_to_word(i);
		printf("\n");
	}
	return 0;
}

void num_to_word(int n)
{
	
	if(n >= 1 && n <= 9)
		ten(n);
	else if(n >= 10 && n <= 19)
		ten1(n);
	else if(n >= 20 && n <= 99)
	{
		ten2(n / 10); printf(" "); ten(n % 10);
	}
	else if(n >= 100 && n <= 119)
	{
		ten(n / 10 / 10); printf(" hundred "); 
		(n >= 100 && n <= 109) ? ten(n % 100) : ten1(n % 100);
	}
	else if(n >= 120 & n <= 999)
	{
		ten(n / 10 / 10); printf(" hundred "); ten2((n % 100) / 10);
		printf(" "); ten(n % 100 % 10);
	}
}

void ten(int n)
{
	switch(n)
	{
		case 1: printf("One");	break;
		case 2: printf("Two");	break;
		case 3: printf("Three"); break;
		case 4: printf("Four");	break;
		case 5: printf("Five");	 break;
		case 6: printf("Six");		break;
		case 7: printf("Seven"); break;
		case 8: printf("Eight");   break;
		case 9: printf("Nine");	 break;
	}
}

void ten1(int n)
{
	switch(n)
	{
		case 10: printf("Ten");	  	   break;
		case 11: printf("Eleven");      break;
		case 12: printf("Twelve");     break;
		case 13: printf("Thirteen");   break;
		case 14: printf("Fourteen");  break;
		case 15: printf("Fifteen");  	 break;
		case 16: printf("Sixteen");      break;
		case 17: printf("Seventeen"); break;
		case 18: printf("Eighteen");	 break;
		case 19: printf("Nineteen");    break;
	}
}

void ten2(int n)
{
	switch(n)
	{
		case 2: printf("Twenty");	break;
		case 3: printf("Thirty");		break;
		case 4: printf("Forty");		 break;
		case 5: printf("Fifty");	 	 break;
		case 6: printf("Sixty");		 break;
		case 7: printf("Seventy");  break;
		case 8: printf("Eighty");	  break;
		case 9: printf("Ninety");	 break;
	}
}
