#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "cpu_time_measure.h"

#define BUF_SIZE 1000000

size_t strlen_v1(const char *src)
{
	size_t len = 0;
//	if(src == NULL) return -1;
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
	char timestr[20] = "";
	struct timeval start;
	struct timeval end;

	char *buf = (char*)malloc(BUF_SIZE);

	if (buf == NULL) {
		printf("malloc memory not avaliable.\n");
		return -1;
	}
	memset(buf,'a',BUF_SIZE);
	buf[BUF_SIZE-1] = '\0'; //add string end null
	
	gettimeofday(&start,NULL);	
	printf("strlen_v1():param string len:%d.\n", (int)strlen_v1(buf));
	gettimeofday(&end,NULL);	
	memset(timestr,'\0',sizeof(timestr));
	printf("strlen_v1(): cpu run %ss.\n",get_cpu_time_used(timestr,&start,&end));

	gettimeofday(&start,NULL);	
	printf("strlen_v2():param string len:%d.\n", (int)strlen_v2(buf));
	gettimeofday(&end,NULL);	
	memset(timestr,'\0',sizeof(timestr));
	printf("strlen_v2(): cpu run %ss.\n",get_cpu_time_used(timestr,&start,&end));

	gettimeofday(&start,NULL);	
	printf("strlen(),lib:param string len:%d.\n", (int)strlen(buf));
	gettimeofday(&end,NULL);	
	memset(timestr,'\0',sizeof(timestr));
	printf("strlen(),lib: cpu run %ss.\n",get_cpu_time_used(timestr,&start,&end));
	
	return 0;
}


