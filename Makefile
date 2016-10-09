file_io:file_io.o
	cc -o file_io file_io.o

file_io.o:file_io.c file_io.h
	cc -c file_io.c

clean:
	rm file_io file_io.o