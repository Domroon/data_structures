#include <stdbool.h> 

typedef struct Item {
    char key[20];
    char value[250];
    void* next;
} Item;

typedef struct Dict {
    void* firstItem;
    long length;
} Dict;

Item* addItem(char key[], char value[], Dict* dict);

bool removeItem(char key[], Dict* dict);

Item* getItem(char key[], Dict* dict);

