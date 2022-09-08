#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>

#define MAX_LEN 100

void clear_screen(void);
void print_encryptedMsg(char msg[]);
void encrypt_message(char msg[], int key);
void read_message(char msg[], int length);
int shift_amount(void);
void clear(char msg[], int length);

int main(void)
{
	bool is_encrypted = false;
	char message[MAX_LEN], command;
	int key = 0, num_encrypt = 0;
	for(;;)
	{
		printf("The very simple message encryptor and decryptor program.\n");
		printf("Enter (E = Enter message\nC = Encrypt message\nD = Decrypt message\nP = Print message\nX = Exit program): ");	
		scanf(" %c", &command);
		printf("\n");
		switch(toupper(command))
		{
			case 'E':
								printf("Enter message to be encrypted: ");
							   read_message(message, MAX_LEN);
					 	     break;
			case 'C':
							{
								printf("Enter shift amount(1 - 25): ");
								key = shift_amount();
								encrypt_message(message, key);
								is_encrypted = true;
								num_encrypt++;
							} break;
			case 'D': 
			            {
			            	if(is_encrypted == true)
			            	{
			            		while(num_encrypt > 0)
			            		{
							  		encrypt_message(message, 26 - key); 
							  		--num_encrypt;
			            		}
							  		is_encrypted = false;
			            	}
							   else
							   		printf("The message is not yet encrypted.\n");
			            }break;
			case 'P': 
							{
								printf("Encrypted message: ");
								print_encryptedMsg(message); break;
								printf("\n");
							}
			case 'X': return 0;
			default:
							{
								printf("Invalid command!\n");
							} break;
		}
		printf("\n");
	}
	
}
void clear(char msg[], int length)
{
	for(int i = 0; i < length; i++)
		msg[i] = ' ';
}
void  read_message(char msg[], int length)
{
	int i = 0, c;
	
	while(getchar() != '\n')
	   ;
	   
	while((c = getchar()) != '\n')
	{
		if(i < length)
			msg[i] = c;
		i++;
	}
	
	msg[i] = '\n';
	
}

int shift_amount(void)
{
	int n;
	printf("Enter shift amount (1 - 25): ");
	scanf("%d", &n);
	
	return n;
}

void encrypt_message(char msg[], int key)
{
	int i = 0;
	while(msg[i] != '\n')
	{
		if(msg[i] >= 'a' && msg[i] <= 'z')
			msg[i] = ((msg[i] - 'a') + key) % 26 + 'a';
		else if(msg[i] >= 'A' && msg[i] <= 'Z')
			msg[i] = ((msg[i] - 'A') + key) % 26 + 'A';
		
		i++;
	}
}

void print_encryptedMsg(char msg[])
{
	int i = 0;
	while((msg[i]) != '\n')
	{
		printf("%c", msg[i]);
		i++;
	}
}

void clear_screen(void)
{
	clrscr();
}
