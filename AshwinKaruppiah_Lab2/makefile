CC = gcc
cflags = -o
hello:
	@echo "Hello!"

compile:
	$(CC) main.c isOdd.c $(cflags) program.exe

run: compile
	@./program.exe

clean:
	@rm -f program.exe

all: compile run clean