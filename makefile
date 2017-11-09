all: hw10.c
	gcc -o run hw10.c

run: all
	./run

clean: 
	rm run
	rm a.out
	rm result.txt