#include <criterion/criterion.h>

#include "../src/linked_list.h"

Test(linkedlist_tests, create){
    Node* added = add(42);
    cr_expect(added != NULL, "add should not return NULL");  
}

Test(linkedlist_tests, create_2){
    Node* added = add(43);
    cr_expect(added->data == 43, "add.data should be 43");  
}