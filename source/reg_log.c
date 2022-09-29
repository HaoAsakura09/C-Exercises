#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNT 100
#define LEN 20

int num_account = 0; // number of accounts stored

struct data
{
	int level;
	int item;
}account_data[MAX_ACCOUNT];
struct Account
{
	char username[LEN + 1];
	char password[LEN + 1];
} account[MAX_ACCOUNT];

int read_line(char str[], int n);

void login(void);
void register_account(void);
int find_account(char user[]);

void print_data(void);
bool login_status(char str[], char pw[]);

int main(void)
{
	char command;
	for(;;)
	{
		printf("Enter command (L=login, R=register, Q=quit): ");
		scanf(" %c", &command);
		while(getchar() == ' ')
			;
		switch(toupper(command))
		{
			case 'L': login(); break;
			case 'R': register_account(); break;
			case 'Q': return 0;
			default: printf("Invalid command!\n"); break;
		}
	}
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	while(isspace((ch = getchar())))
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

int find_account(char user[])
{
	int i ;
	for(i = 0; i < num_account; i++)
		if(strcmp(user, account[i].username) == 0)
			return 1;
		return 0;
}

void register_account(void)
{
	char user[LEN + 1], pw[LEN + 1];
	
	int account_exist;
	printf("Registration:\n");
	printf("Enter username: ");
	read_line(user, LEN);
	printf("Enter password: ");
	read_line(pw, LEN);
	
	if(num_account == MAX_ACCOUNT)
	{
		printf("Database is full!\n");
		return;
	}
	
	account_exist = find_account(user);
	if(account_exist == 1)
	{
		printf("Username is already taken.\n");
		return;
	}
	else
	{
		strcpy(account[num_account].username, user);
		strcpy(account[num_account].password, pw);
		num_account++;
		printf("Successfuly registered!\n");
	}
}

bool login_status(char str[], char pw[])
{
	int i;
	for(i = 0; i < num_account; i++)
		if(strcmp(account[i].username, str) == 0 &&
			 strcmp(account[i].password, pw) == 0)
			 	return true;
	    return false;
}
void login(void)
{
	char user[LEN + 1], pw[LEN + 1];
	printf("Login:\n");
	printf("Enter your username: ");
	read_line(user, LEN);
	printf("Enter your password: ");
	read_line(pw, LEN);
	
	if(login_status(user, pw) == true)
	{
		printf("Login successfully.\n");
		print_data();
		return;
	}
	else
	{
		printf("Incorrect username or password\n");
		return;
	}
}

void print_data(void)
{
	int i;
	for(i = 0; i < num_account; i++)
	{
		printf("Your item: %d\n", account_data[i].item);
		printf("Your level: %d\n", account_data[i].level);
	}
}
