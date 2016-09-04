EXEC  = power_method
DFLAG = -Wall
CFLAG = -std=c99 -lm -llapacke -lblas -march=native -Ofast

all:
	gcc main.c fonctions.c -o $(EXEC) $(CFLAG) $(DFLAG)

run:
	./$(EXEC)

help:
	@echo "****** Makefile help ******"
	@echo "Here is a summary of all the options"
	@echo
	@echo "make help    display this help"
	@echo "make         compile all the source files."
	@echo "make run     execute the code."
	@echo "make clean   delete the execution file."

clean:
	rm $(EXEC) 
