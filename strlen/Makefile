CC = gcc

strlen-prac:strlen-prac.o cpu_time_measure.o
	$(CC) $(CFLAGS) -o $@ $^
cpu_time_measure.o:cpu_time_measure.h
strlen-prac.o:cpu_time_measure.h
clean:
	rm -f strlen-prac *.o
