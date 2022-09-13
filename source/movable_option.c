#include <ctype.h>
#include <stdbool.h>
#include <conio.h>
#include <stdio.h>

#define MAX_ACCOUNT 100
#define USER_LEN 20
#define PW_LEN 20 
// clear console
void clear_screen(void);

struct Database
{
	char username[USER_LEN];
	char password[PW_LEN];
}account[MAX_ACCOUNT];

int menu(void);

int main(void)
{
	int menu_return;
	char cmd;
	
	for(;;)
	{
		printf("\n==================================\n");
		printf("    Very basic account database\n");
		printf("==================================\n");
      printf("Press a or d to move...\n");
      menu_return = menu();
      clear_screen();
      switch(menu_return)
      {
      	case 0: printf("Login\n"); break;
      	case 1: printf("Register\n"); break;
      	case 2: printf("Modify\n"); break;
      	case 3: printf("Delete\n"); break;
      	case 4: printf("Print account\n"); break;
      }
		
			break;
	}
	return 0;
}

int menu(void)
{
	int ch;
	char menu[5][15] = { {"Login"}, {"Register"}, {"Modify"}, {"Delete"}, {"Print account"} };
	
	bool is_right, is_left;
	int move;
			move = 0;
	
	for(;;)
	{
		is_right = is_left = false;
		switch(toupper((ch = getch())))
	   {
			case 'D': is_right = true; break;
			case 'A': is_left = true; break;
			case 10: return move;
	   }
	   
	  if(is_right && move >= 0 && move < 5 - 1) 
	  {
	  	move++;
	  }
	  else if(is_left && move > 0 && move < 5) 
	 {
	 	 move--;
	 }
	  clear_screen();
	  
	  printf("Menu: ");
	  for(int row = 0; row < 5; row++)
	  {
	  	if(row == move)
	  	{
	  		printf("%s option\n", menu[move]);
	  		break;
	  	}
	  	else
	  	{
	  		printf("      ");
	  	}
	  }
	  
	}
}
void clear_screen(void)
{
	clrscr();
}
