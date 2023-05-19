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

// Test(add, wrong_type){
//     Node* added = add('a');
//     cr_expect(added == NULL, "add should return NULL");  
// }

// Test(add, wrong_type_2){
//     Node* added = add("Hello World");
//     cr_expect(added == NULL, "add should return NULL");  
// }


//insert
Test(insert, node_not_found){
    Node* added = add(43);
    add(41);
    add(42);
    add(43);
    add(44);
    Node* ins = insert(45, 46);
    cr_expect(ins == NULL, "Node should be NULL");  
}

Test(insert, successfully_inserted){
    Node* added = add(43);
    add(41);
    add(42);
    add(43);
    add(44);
    Node* ins = insert(45, 44);
    cr_expect(ins->data == 45, "Node data should be 44");  
}


//removeNode
Test(removeNode, successfully_removed){
    Node* added = add(43);
    add(41);
    add(42);
    add(43);
    add(44);
    Node* del = removeNode(42);
    cr_expect(del == NULL, "Should return NULL");  
}

Test(removeNode, node_not_found){
    Node* added = add(43);
    add(41);
    add(42);
    add(43);
    add(44);
    Node* del = removeNode(45);
    cr_expect(del == -1, "Should return -1");  
}


// show_list

Test(show_list, check_stdout){
    FILE *fp;
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