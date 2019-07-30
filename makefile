output: main.o sum.o
	gcc -g main.o sum.o 

main.o: main.c
	gcc -c main.c

sum.o: sum.c
	gcc -c sum.c

clean:
	rm *.o output
