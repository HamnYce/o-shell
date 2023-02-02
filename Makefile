all: compile run


compile:
	gcc -o build/osh osh.c

run:
	build/osh
