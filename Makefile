SRC=src
SRCS=$(wildcard $(SRC)/*.c)

TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TESTBINS=$(pathsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

# compiling

all: bin/main

bin/main: obj/test_linked_list.o obj/linked_list.o
	@echo "Linking and producing the final application"
	gcc -w -o bin/main obj/test_linked_list.o obj/linked_list.o

obj/test_linked_list.o: src/test_linked_list.c
	@echo "Compiling test_linked_list"
	gcc -w -c src/test_linked_list.c -o obj/test_linked_list.o

obj/linked_list.o: src/linked_list.c
	@echo "Compiling linked_list"
	gcc -w -c src/linked_list.c -o obj/linked_list.o


# test

test: tests/bin/test_linked_list
	@echo "Start test_linked_list"
	./tests/bin/test_linked_list2 --verbose

tests/bin/test_linked_list: obj/linked_list.o obj/test_linked_list2.o
	@echo "Linking and producing the test for linked_list"
	gcc obj/linked_list.o obj/test_linked_list2.o -o tests/bin/test_linked_list2 -lcriterion

obj/test_linked_list2.o: tests/test_linked_list2.c
	@echo "Compiling test_linked_list2"
	gcc -c tests/test_linked_list2.c -o obj/test_linked_list2.o  

$(TEST)/bin:
	mkdir $@


# clean

clean:
	@echo "Delete data in bin, obj and tests/bin directories"
	rm -r bin/* obj/* tests/bin/*

