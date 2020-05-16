
CC = gcc

FLAGS = \
-Wall \
-Werror

INCLUDES = \


SOURCES = \
main.c

OUTPUT = budgeteer-cli

all:
	$(CC) $(FLAGS) $(INCLUDES) $(SOURCES) -o $(OUTPUT)

clean:
	rm $(OUTPUT)

run:
	./$(OUTPUT)
