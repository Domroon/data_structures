#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include "dict.h"


Item* addItem(char key[], char value[], Dict* dict) {
    Item* item = malloc(sizeof(Item));
    // was the program able to allocate memory in heap?
    if (item == NULL)
        return NULL;

    if (dict->firstItem == NULL) {
        dict->firstItem = item;
        item->next = NULL;
        strcpy(item->key, key);
        strcpy(item->value, value);
    } else {
        // check whether key is already assigned
        Item* keyCheck = getItem(key, dict);
        if (keyCheck != NULL) {
            return NULL;
        }

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
    Item* current = dict->firstItem;
    while (current !=NULL) {
        if (strcmp(current->key, key) == 0){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void showAllItems(Dict* dict) {
    Item* current = dict->firstItem;
    printf("{");
    while (current !=NULL) {
        printf("\"%s\": %s, ", current->key, current->value);

        current = current->next;
    }
    printf("}\n");
}