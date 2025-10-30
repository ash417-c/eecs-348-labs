CC = g++
cflags = -o

all: compile

compile:
	$(CC) matrix.cpp $(cflags) matrix.exe

run: compile
	./matrix.exe

clean:
	rm -f matrix.exe

help:
	@echo "Available commands:"
	@echo "compile -- compiles matrix.cpp"
	@echo "run -- runs matrix.exe"
	@echo "clean -- deletes exe file"