EXEC=power_method
DFLAG=-Wall
CFLAG=-std=c99 -lm -llapacke -lblas -march=native -Ofast

all:
	gcc main.c fonctions.c -o $(EXEC) $(CFLAG) $(DFLAG)

run:
	./$(EXEC)

help:
	@echo "****** Makefile help ******"
	@echo "Here is a summary of all the options"
	@echo "make\t\t This will compile all the source files."
	@echo "make run\t This will execute the code."
	@echo "make clean\t This will delete the execution file."

clean:
	rm $(EXEC) 
