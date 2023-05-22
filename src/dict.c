#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include "dict.h"


Item* addItem(char key[], char value[], Dict* dict) {
    Item* item = malloc(sizeof(Item));
    // was the program able to allocate memory in heap?
    if (item == NULL)
        return NULL;

    printf("success generated item\n");
    if (dict->firstItem == NULL) {
        dict->firstItem = item;
        printf("firstItem is null\n");
        item->next = NULL;
        strcpy(item->key, key);
        strcpy(item->value, value);
    } else {
        item->next = dict->firstItem;
        strcpy(item->key, key);
        strcpy(item->value, value);
        dict->firstItem = item;
    }
    return item;
}

bool removeItem(char key[], Dict* dict) {
    return false;
}

Item* getItem(char key[], Dict* dict) {
    Item* firstItem = dict->firstItem;
    return firstItem;
}