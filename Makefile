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

clean:
	@echo "Delete data in bin and obj directories"
	rm -r bin/* obj/*