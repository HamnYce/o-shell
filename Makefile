all: compile run


compile:
	gcc -o osh osh.c

run:
	./osh
