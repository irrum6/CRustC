.DEFAULT_GOAL : all
all : build
build:
	gcc main.c -o program
clean:
	rm -f program
run:
	./program
test:
	./program 3 + 3
	./program 3 - 3
	./program 3 "*" 3 #just *causes errors
	./program 3 / 3