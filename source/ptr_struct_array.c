#include <stdio.h>
#include <string.h>

struct person
{
	char *first_name;
	char *last_name;
};

const struct person info[] =
{
	{"Naruto", "Uzumaki"},
	{"Sasuke", "Uchiha"},
	{"Sakura", "Haruno"},
	{"Kakashi", "Hatake"}
};

int main(void)
{
	struct person *ninja = &info;
	
	for(int i = 0; i < 4; i++)
	{
		printf("%s %s\n", ninja[i].last_name, ninja[i].first_name);
	}
	return 0;
}
