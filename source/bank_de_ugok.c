#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNT 1
#define NAME_LEN 20
struct Account
{
	char name[NAME_LEN];
	int pin_code;
} account[MAX_ACCOUNT];

int num_account = 0; // number of accounts stored in database

bool check_pin(int account_index, int pin);
int find_account(char str[]);
int pin_code(void);
void login(void);
int menu(void);
int read_line(char str[], int n);
void clear(void);

int main(void)
{
	int r_menu;
	for(;;)
	{
		r_menu = menu();
		switch(r_menu)
		{
			case 0:  printf("Register\n"); break;
			case 1: login(); break;
			case 2: printf("Logged out\n"); return 0;
		}
	}
}
void clear(void)
{
	clrscr();
}

int menu(void)
{
   bool up, down;
   int m_select = 0;
   char move;
   		
   for(;;)
   {
   	printf("\n------------------------------------\n");
   	printf("|           Banko ng Ugok          |");
   	printf("\n------------------------------------\n");
   	if(m_select == 0)
   	{
   		printf("Register <---\n");
   		printf("Login\n");
   		printf("Log out\n");
   	}
   	else if(m_select == 1)
   	{
   		printf("Register\n");
   		printf("Login <---\n");
   		printf("Log out\n");
   	}
   	else if(m_select == 2)
   	{
   		printf("Register\n");
   		printf("Login\n");
   		printf("Log out <---\n");
   	}
   		
   	up = down = false;
   	switch(toupper(move = getch()))
   	{
   		case 'W': up = true; break;
   		case 'S': down = true; break;
   	}
   	
   	if(up && m_select > 0)
   		--m_select;
   	else if(down && m_select < 2)
   		++m_select;
   	
   	clear();
   	 if((int)move == 10)
   		return m_select;
   }
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

int pin_code(void)
{
	int p_c, num_digits = 0, copy_p_c;
	
	scanf("%d", &p_c);
	copy_p_c = p_c;
	
   do
   {
   	copy_p_c /= 10;
   	num_digits++;
   }while(copy_p_c > 0);
  
  if(num_digits == 6)
  	return p_c;
  else
  	return -1;
}

bool check_pin(int account_index, int pin)
{
	if(account[account_index].pin_code == pin)
		return true;
	return false;
}
int find_account(char str[])
{
	for(int i = 0; i < num_account; i++)
		if(strcmp(account[i].name, str) == 0)
			return i; // Index of an account
		return -1;
}
void login(void)
{
	char name[NAME_LEN];
	int pincode, a_index = 0;
	bool is_pin_valid, login_status = false;
	do
	{
		printf("\n------------------------------------\n");
	   printf("|           Banko ng Ugok          |");
		printf("\n------------------------------------\n");
	
		
		printf("Enter account name: ");
		read_line(name, NAME_LEN);
		printf("Enter your pin code: ");
		pincode = pin_code();
	//	getchar();
		is_pin_valid = check_pin(a_index, pincode);
		a_index = find_account(name);
		
		if(a_index >= 0 && is_pin_valid)
		{
			clear();
			printf("Logged in successfully!\n");
			login_status = true;
			break;
		}
		else if(login_status == false)
		{
			clear();
			printf("\n\nAccount doesn't match\n");
		}
	}while(1);
	
}
