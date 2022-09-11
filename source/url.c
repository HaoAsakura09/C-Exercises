#include <stdio.h>
#include <string.h>

void build_url_index(const char *domain, char *index_url);

int main(void)
{
	char domain_str[50] = {"knking.com"};
	char index_str[50];
	build_url_index(domain_str, index_str);
	
	printf("%s\n", index_str);
	return 0;
}

void build_url_index(const char *domain, char *index_url)
{
	char str[50] = {"http://"};
	strcpy(index_url, strcat(strcat(str, domain), "/index.html"));
}
