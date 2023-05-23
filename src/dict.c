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
    dict->length++;
    return item;
}

bool removeItem(char key[], Dict* dict) {
    Item* previousItem = dict->firstItem;

    // first Item is Item that should be deleted
    if (strcmp(previousItem->key, key) == 0){
        // point to the next item and delete the prev item
        dict->firstItem = previousItem->next;
        free(previousItem);
        dict->length--;
        return true;
    }

    // currentItem is one step further than previousItem
    Item* currentItem = dict->firstItem;
    currentItem = currentItem->next;
    while (currentItem != NULL) {
        if (strcmp(currentItem->key, key) == 0){
            previousItem->next = currentItem->next;
            free(currentItem);
            dict->length--;
            return true;
        }

        currentItem = currentItem->next;
        previousItem = previousItem->next;
    }
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