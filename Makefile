
CC = gcc

FLAGS = \
-Wall \
-Werror

INCLUDES = \
-Istructs

SOURCES = \
main.c

OUTPUT = budgeteer-cli

all:
	$(CC) $(FLAGS) $(INCLUDES) $(SOURCES) -o $(OUTPUT)

clean:
	rm $(OUTPUT)

run:
	./$(OUTPUT)
