

all:
	gcc main.c -o budgeteer-cli

clean:
	rm budgeteer-cli

run:
	./budgeteer-cli
