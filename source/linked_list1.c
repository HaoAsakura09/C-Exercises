#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

int main(void)
{
	struct node *first = NULL;
	struct node *new_node;
	
	// firat new node
	new_node = malloc(sizeof(struct node));
	new_node -> value = 20;
	new_node -> next = first; // points to NULL
	first = new_node;
	
	// second 
	new_node = malloc(sizeof(struct node));
	new_node -> value = 30;
	new_node -> next = first; 
	first = new_node;
	
	// third
	new_node = malloc(sizeof(struct node));
	new_node -> value = 40;
	new_node -> next = first;
	first = new_node;
	
	struct node *p;
	
	for(p = first; p != NULL; p = p -> next)
		printf(" %d", p -> value);
	return 0;
}
