#include "linked_list.h"

int main(){
    add(42);
    add(43);
    add(44);
    show_list();
    insert(8, 2);
    show_list();
    insert(8, 43);
    show_list();
    removeNode(42);
    show_list();
    removeNode(8);
    show_list();
    return 0;
}

