#ifndef _CPU_TIME_MEASURE_H_
#define _CPU_TIME_MEASURE_H_

#include <sys/time.h>

extern char *get_cpu_time_used(char *dest,  struct timeval *start, struct timeval *end);


#endif
