#include <sys/time.h>
#include <stdio.h>
#include "cpu_time_measure.h"

char *get_cpu_time_used(char *dest,struct timeval *start, struct timeval *end)
{
	double cpu_time_used = 0;
	cpu_time_used = ((double)(1000000*(end->tv_sec - start->tv_sec) + 
								end->tv_usec -start->tv_usec))/1000000;
	sprintf(dest,"%.8f",cpu_time_used);
	return dest;
}
