#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension);
int main(void)
{
	char str[] = "file.txt";
	char str2[10];
	
	get_extension(str, str2);
	
	printf("%s\n", str2);
	return 0;
}

void get_extension(const char*file_name, char *extension)
{	
	const char *p = file_name;
	char dot;
	
	while(*p != '\0')
	{
		if(*p == '.')
			dot = *p;
		p++;
	}
	
	if(dot == '.')
	{
		while(*file_name++ != '.') ;
		strcpy(extension, file_name);
	}
	else
		strcpy(extension, " ");
}
