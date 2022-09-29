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

int main(void)
{
	struct node *first = NULL;
	struct node *new_node;
	
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
	
	print_name(first);
	return 0;
}

void print_name(const struct node *name)
{
	const struct node *p;
	for(p = name; p != NULL; p = p -> next)
		printf(" %s", p -> name);
}
