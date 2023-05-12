#include <stdio.h>
#include <sys/stat.h>
#include <criterion/criterion.h>

#include "../src/linked_list.h"


// add

Test(add, create){
    Node* added = add(42);
    cr_expect(added != NULL, "add should not return NULL");  
}

Test(add, create_2){
    Node* added = add(43);
    cr_expect(added->data == 43, "add.data should be 43");  
}

Test(add, wrong_type){
    Node* added = add('a');
    cr_expect(added == NULL, "add should return NULL");  
}

Test(add, wrong_type_2){
    Node* added = add("Hello World");
    cr_expect(added == NULL, "add should return NULL");  
}


//insert


//removeNode


// show_list

Test(show_list, check_stdout){
    FILE *fp;
    FILE *fp2;
    char output[100];

    // Add Data
    add(43);
    add(42);
    add(52);
    add(111);

    // Redirect stdout
    fp = freopen("./tests/redir.txt", "w", stdout);

    show_list();

    fclose(fp);

    // assert checking
    fp = fopen("./tests/redir.txt", "r");
    char buff[255];
    fscanf(fp, "%s", buff);
    int matches = strcmp(buff, "111->52->42->43->");
    cr_expect(matches == 0, "shows not the expected string to stdout");
}