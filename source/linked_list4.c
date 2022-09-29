#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

struct node
{
	char name[LEN + 1];
	struct node *next;
};

void print_name(const struct node *name);

struct node *add_name(struct node *name, char *str)
{
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("Error: malloc() failed in add_name()\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new_node -> name, str);
	new_node -> next = name;
	return new_node;
}

int read_line(char str[], int length);

struct node *read_name(void)
{
	struct node *first = NULL;
	char user_name[LEN + 1], ch = 'y';
	
	printf("Enter name: ");
  for(;;)
	{
		read_line(user_name, LEN);
		printf("Do you want to add more? (Y / N): ");
		
	  first = add_name(first, user_name);
		scanf(" %c", &ch);
		if(ch == 'n' || ch == 'N')
			break;
	}
	return first;
}

int main(void)
{
	struct node *first = NULL;
	
	first = read_name();

/*	struct node *new_node;
	
	new_node = malloc(sizeof(struct node));
	strcpy(new_node -> name, "Naruto");
	new_node -> next = first;
	first = new_node;
	
	new_node = malloc(sizeof(struct node));
	strcpy(new_node -> name, "Sasuke");
	new_node -> next = first;
	first = new_node;
	
	new_node = malloc(sizeof(struct node));
	strcpy(new_node -> name, "Sakura");
	new_node -> next = first;
	first = new_node;
	
	new_node = malloc(sizeof(struct node));
	strcpy(new_node -> name, "Kakashi");
	new_node -> next = first;
	first = new_node;
	*/
	print_name(first);
	return 0;
}

int read_line(char str[], int length)
{
	int ch, i = 0;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && ch != EOF)
	{
		if( i < length)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

void print_name(const struct node *name)
{
	const struct node *p;
	for(p = name; p != NULL; p = p -> next)
		printf(" %s", p -> name);
}
