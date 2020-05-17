
CC = gcc

FLAGS = \
-Wall \
-Werror

INCLUDES = \
-Istructs

SOURCES = \
main.c

OUTPUT = budgeteer-cli

TEST_SOURCES = \
test.c

TEST_OUTPUT = budgeteer-tests

all:
	$(CC) $(FLAGS) $(INCLUDES) $(SOURCES) -o $(OUTPUT)

test:
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_SOURCES) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

clean:
	if [ -e $(OUTPUT) ]; then rm $(OUTPUT); fi
	if [ -e $(TEST_OUTPUT) ]; then rm $(TEST_OUTPUT); fi

run:
	./$(OUTPUT)
