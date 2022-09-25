#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_STUDENT 100
#define NAME_LEN 20

int number_of_students = 0;

struct student
{
	char first_name[NAME_LEN + 1];
	char last_name[NAME_LEN + 1];
} name[NUM_STUDENT];


int read_line(char str[], int length);

void print_student(void);
void insert(void);
void search(void);

int main(void)
{
	char command;
	
	for(;;)
	{
		printf("Enter i = insert, s = search, p = print, q = quit: ");
		scanf(" %c",  &command);
		
		switch(toupper(command))
		{
			case 'I': insert(); break;
			case 'S': search(); break;
			case 'P': print_student(); break;
		}
		
		if(command == 'q' || command == 'Q')
			break;
	}
	
	return 0;
}

int read_line(char str[], int length)
{
	int i = 0, ch;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < length)
			str[i++] = ch;
		
		ch = getchar();
	}
	str[i] = '\0';
	return i;	
}

void insert(void)
{
	if(number_of_students == NUM_STUDENT)
	{
		printf("There's no available for students.\n");
		return;
	}
		
	printf("Enter student first name: ");
	read_line(name[number_of_students].first_name, NAME_LEN);
	printf("Enter student last name: ");
	read_line(name[number_of_students].last_name, NAME_LEN);
	number_of_students++;
}

void search(void)
{
	char first_name[NAME_LEN + 1], last_name[NAME_LEN + 1];
	printf("Enter the first name of student: ");
		read_line(first_name, NAME_LEN);
	printf("Enter the last name of student: ");
		read_line(last_name, NAME_LEN);
		
	for(int i = 0; i < number_of_students; i++)
	{
		if(strcmp(first_name, name[i].first_name) == 0 &&
			strcmp(last_name, name[i].last_name) == 0)
		{
				printf("Student found:\n");
				printf("First name: %s, Last name: %s\n", name[i].first_name, name[i].last_name);	
				return;
		}
		
		printf("Student not found.\n");
		return;
	}
}

void print_student(void)
{
	printf("\tNumber of students: %d\n", number_of_students);
	printf("   First name\tLast name\n");
	for(int i = 0; i < number_of_students; i++)
	{
		printf("%d. %s\t%s\n", i + 1, name[i].first_name, name[i].last_name);
	}
}
