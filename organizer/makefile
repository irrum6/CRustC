.DEFAULT_GOAL: build
build:
	gcc main.c read.c event.c -std=c11 -o ./bin/program
build_debug:
	gcc main.c read.c event.c -std=c11 -g -o ./bin/debug.out
clean:
	rm -f ./bin/program
	rm -f ./bin/debug.out
run:
	./bin/program
runbb:
	./bin/program bb
debug:
	gdb ./bin/debug.out
