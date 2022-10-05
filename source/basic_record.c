#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT 100
#define MAX_LEN 30

int num_student = 0;

struct database
{
	char name[MAX_LEN];
	int age;
	struct database *next;
};

struct database *insert(struct database *s, char *s_name, int age)
{
	struct database *new_node;
	new_node = malloc(sizeof(struct database));
	if(new_node == NULL)
	{
		printf("Memory allocation in insert() failed!\n");
		exit(EXIT_FAILURE);
	}
	
	strcpy(new_node -> name, s_name);
	new_node -> age = age;
	new_node -> next = s;
	return new_node;
}

int read_name(char str[], int len);

struct database *read_data(struct database *first)
{
	char name[MAX_LEN];
	int age;
	
	if(num_student == MAX_STUDENT)
	{
		printf("Database is full\n");
		exit(EXIT_FAILURE);
	}

   char cmd;
   
	for(;;)
	{
		printf("Enter student name: ");
		read_name(name, MAX_LEN);
		printf("Enter age: ");
		scanf("%d", &age);
		
		first = insert(first, name, age);
		num_student++;
		printf("Do you want to add more students? (Y/N): ");
		scanf(" %c", &cmd);
		if(toupper(cmd) == 'N')
			break;
	}
	return first;
}

void search(struct database *s);
void print_student(struct database *s);

struct database *delete(struct database *s)
{
	struct database *prev, *curr;
	
	if(num_student == 0)
	{
		printf("Database is empty.\n");
		return s;
	}
	char name[MAX_LEN];
	printf("Enter the name of student you want to delete: ");
	read_name(name, MAX_LEN);
	
	for(curr = s, prev = NULL; curr != NULL; prev  = curr -> next, curr = curr -> next)
		if(strcmp(curr -> name, name) == 0)
			break;
			
	if(curr == NULL)
	{
		printf("Student not found.\n");
		return s;
	}
	else if(prev == NULL)
		s = s -> next;
	else
		prev -> next = curr -> next;
	free(curr);
	return s;
}

int main(void)
{
	struct database *student = NULL;
	char command;

	for(;;)
	{
		printf("Enter a command( i = insert, s = search, d = delete, p = print, q = quit): ");
		scanf(" %command", &command);
		// insert
		// search
		// delete
		// print students
		// q to quit
		clrscr();
		switch(toupper(command))
		{
			case 'I': student = read_data(student); break;
			case 'P': print_student(student); break;
			case 'S': search(student); break;
			case 'D': student = delete(student); break;
			case 'Q': return 0;
			default: printf("Invalid command!\n");
		}
	}
	
}

int read_name(char str[], int len)
{
	int ch, i = 0;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < len)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

void print_student(struct database *s)
{
	if(num_student == 0)
	{
		printf("Database is empty!\n");
		return;
	}
	
	printf("Name\t\tAge\n");
	for(; s != NULL; s = s -> next)
		printf("%s\t%d\n", s -> name, s -> age);
}

void search(struct database *s)
{
	char name[MAX_LEN];
	
	if(num_student == 0)
	{
		printf("Database in empty.\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Search student:\n");
	
	printf("Enter name: ");
	read_name(name, MAX_LEN);
	
	for(; s != NULL; s = s -> next)
		if(strcmp(s -> name, name) == 0)
		{
			printf("Student found:\n");
			printf("Name: %s, Age: %d\n", s -> name, s -> age);
			return;
		}
	printf("Student not found.\n");
}
