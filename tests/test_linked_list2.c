#include <criterion/criterion.h>

#include "../src/linked_list.h"

Test(linkedlist_tests, create){
    struct Node* added = add(42);
    cr_expect(added != NULL, "add should not return NULL");  
}