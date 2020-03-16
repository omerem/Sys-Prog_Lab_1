all: encoder


encoder: encoder.o encoder.o
	gcc -g -Wall -o encoder encoder.o

encoder.o: encoder.c basicEncoder.o
	gcc -g -Wall -c -o encoder.o encoder.c

basicEncoder.o: basicEncoder.c
	gcc -g -Wall -c -o basicEncoder.o basicEncoder.c

.PHONY: clean

clean: 
	rm -f *.o encoder
	rm -f text.txt encoder
