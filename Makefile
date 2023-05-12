SRC=src
SRCS=$(wildcard $(SRC)/*.c)

TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TESTBINS=$(pathsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

# compiling

all: bin/main

bin/main: obj/main.o obj/linked_list.o
	@echo "Linking and producing the final application"
	gcc -w -o bin/main obj/main.o obj/linked_list.o

obj/main.o: src/main.c
	@echo "Compiling main"
	gcc -w -c src/main.c -o obj/main.o

obj/linked_list.o: src/linked_list.c
	@echo "Compiling linked_list"
	gcc -w -c src/linked_list.c -o obj/linked_list.o


# test

test: tests/bin/main
	@echo "Test linked list"
	./tests/bin/test_linked_list

test-v: tests/bin/main
	@echo "Test linked list (verbose)"
	./tests/bin/test_linked_list --verbose

tests/bin/main: obj/linked_list.o obj/test_linked_list.o
	@echo "Linking and producing the test for linked_list"
	gcc obj/linked_list.o obj/test_linked_list.o -o tests/bin/test_linked_list -lcriterion

obj/test_linked_list.o: tests/test_linked_list.c
	@echo "Compiling test_linked_list"
	gcc -c tests/test_linked_list.c -o obj/test_linked_list.o  

$(TEST)/bin:
	mkdir $@


# clean

clean:
	@echo "Delete data in bin, obj and tests/bin directories"
	rm -r bin/* obj/* tests/bin/*

start:
	./bin/main
