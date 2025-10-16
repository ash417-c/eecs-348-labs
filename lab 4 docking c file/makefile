CC = gcc
cflags = -o
hello:
	@echo "Hello!"

compile:
	$(CC) main.c isOdd.c $(cflags) main.exe

run: compile
	@./main.exe

clean:
	@del -f main.exe

all: compile run