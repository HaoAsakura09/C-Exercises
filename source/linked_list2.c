#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *add_list(struct node *list, int n)
{
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("ERROR: malloc() failed in add_list()\n");
		exit(EXIT_FAILURE);
	}
	new_node -> value = n;
	new_node -> next = list;
	return new_node;
}

int main(void)
{
	struct node *first = NULL;
	
	first = add_list(first, 20);
	first = add_list(first, 30);
	first = add_list(first, 40);
	
	struct node *p;
	
	for(p = first; p != NULL; p = p -> next)
		printf(" %d", p -> value);
	return 0;
}
