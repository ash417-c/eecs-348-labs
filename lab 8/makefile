CC = gcc

TEMP = Temp-Conversion
SCORE = NFL-score-calculator

all: $(TEMP) $(SCORE)

$(TEMP): Temp-Conversion.c
	$(CC) Temp-Conversion.c -o $(TEMP)

$(SCORE): NFL-score-calculator.c
	$(CC) NFL-score-calculator.c -o $(SCORE)

run-temp: $(TEMP)
	./$(TEMP)

run-score: $(SCORE)
	./$(SCORE)

clean:
	rm -f $(TEMP) $(SCORE)

help:
	@echo "Available commands:"
	@echo "all       -- compiles both files"
	@echo "run-temp  -- runs Temp-Conversion.exe"
	@echo "run-score -- runs NFL-score-calculator.exe"
	@echo "clean     -- deletes both exe files"