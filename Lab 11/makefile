CC = g++
CFLAGS = -Wall -g  # Optional: Adds debugging and warning flags
OUT = lab11  # The name of the output executable file

all: compile

compile:
	$(CC) lab11.cpp $(CFLAGS) -o $(OUT)

run: compile
	./$(OUT)

clean:
	rm -f $(OUT)

help:
	@echo "Available commands:"
	@echo "compile -- compiles lab11.cpp"
	@echo "run -- runs the lab11 executable"
	@echo "clean -- deletes the executable file"