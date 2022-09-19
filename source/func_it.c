#include <conio.h>
#include <stdio.h>

int funct1(void);
int  funct2(void);
int  funct3(void);
int funct4(void);
int funct5(void);

int main(void)
{
	int num_func, current_func = -1;
	char cmd;
	for(;;)
	{
		printf("Which function would you like to execute?\n");
		printf("1 = funct1, 2 = ... 3 = ... 4 = ... 5 = .... : ");
		scanf("%d", &num_func);
		if(num_func <= 0 || num_func > 5)
		{
			printf("There's no such function exists.\n");
			continue;
		}
		
	current_func = num_func;	
	while(current_func != 0)
	{	
		clrscr();
		switch(current_func)
		{
			case 1: current_func = funct1(); break;
			case 2: current_func = funct2(); break;
			case 3: current_func = funct3(); break;
			case 4: current_func = funct4(); break;
			case 5: current_func = funct5();break;
		}
	}
		
		printf("Do you want to quit now? (Y/N): ");
		scanf(" %c", &cmd);
		
		if(cmd == 'Y' || cmd == 'y')
			break;	
	}
}

int funct1(void)
{
	int go;
	printf("You are in function 1.\n");
	printf("You can go to function 2.");
	scanf("%d", &go);
	
    for(;;)
	{
		if(go == 1)
			printf("You are already in function %d\n", go);
		if(go == 2)
			break;
		printf("You can't go there!\n");
		printf("You can enter 0 to exit.");
		scanf("%d", &go);
		
		if(go == 0)
			break;
	}
	return go;
}

int funct2(void)
{
	int go;
	printf("You are in function 2.\n");
	printf("You can go to function 1 or 3.");
	scanf("%d", &go);
	
   for(;;)
	{
		if(go == 2)
			printf("You are already in function %d\n", go);
		if(go == 1 || go == 3)
			break;
		printf("You can't go there!\n");
		printf("You can enter 0 to exit.");
		scanf("%d", &go);
		
		if(go == 0)
			break;
	}
	return go;
}

int funct3(void)
{
	int go;
	printf("You are in function 3.\n");
	printf("You can go to function 2 or 4.");
	scanf("%d", &go);
	
    for(;;)
	{
		if(go == 3)
			printf("You are already in function %d\n", go);
		if(go == 2 || go == 4)
			break;
		printf("You can't go there!\n");
		printf("You can enter 0 to exit.");
		scanf("%d", &go);
		
		if(go == 0)
			break;
	}
	return go;
}

int funct4(void)
{
	int go;
	printf("You are in function 4.\n");
	printf("You can go to function 3 or 5.");
	scanf("%d", &go);
	
    for(;;)
	{
		if(go == 4)
			printf("You are already in function %d\n", go);
		if(go == 3 || go == 5)
			break;
		printf("You can't go there!\n");
		printf("You can enter 0 to exit.");
		scanf("%d", &go);
		
		if(go == 0)
			break;
	}
	return go;
}


int funct5(void)
{
	int go;
	printf("You are in function 5.\n");
	printf("You can go to function  4.");
	scanf("%d", &go);
	
    for(;;)
	{
		if(go == 5)
			printf("You are already in function %d\n", go);
		if(go == 4)
			break;
		printf("You can't go there!\n");
		printf("You can enter 0 to exit.");
		scanf("%d", &go);
		
		if(go == 0)
			break;
	}
	return go;
}
