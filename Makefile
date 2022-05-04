garbage: threads_sum.c
	gcc -pthread -o garbage threads_sum.c -W -Wall -pedantic

.PHONY: clean run

run:
	./garbage

clean:
	rm -rf garbage