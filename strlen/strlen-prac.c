#include <string.h>
#include <stdlib.h>
#include <stdio.h>


size_t strlen_v1(const char *src)
{
	size_t len = 0;
	if(src == NULL) return 0;
	while(*src++ != '\0')
		len++;
	return len;
}

size_t strlen_v2(const char *src)
{
	const char *s;
	for (s = src; *s != '\0'; s++);
	return (s-src);
}


int main(int argc, char *argv[])
{
	if(argc != 2) return -1;
	printf("strlen_v1():param string len:%d.\n", (int)strlen_v1(argv[1]));
	printf("strlen_v2():param string len:%d.\n", (int)strlen_v2(argv[1]));
}


