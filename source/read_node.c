#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *read_node(struct node *l);

int main(void)
{
	struct node *h = NULL, *p;
	h = read_node(h);
	
	
	printf("Data entered in the list:\n");
	for(p = h; p != NULL; p = p -> next)
		printf("Data = %d\n", p -> value);
	return 0;
}

struct node *read_node(struct node *l)
{
	int n, i = 0, d;
	struct node *new_node;
	
	printf("Input the number of nodes: ");
	scanf("%d", &n);
	
	while(i < n)
	{
		new_node = malloc(sizeof(struct node));
		if(new_node == NULL)
		{
			printf("Memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}
		printf("Input the data node for %d: ", i + 1);
		scanf("%d", &d);
		new_node -> value = d;
		new_node -> next = l;
		l = new_node;
		i++;
	}
	
	return new_node;
}
