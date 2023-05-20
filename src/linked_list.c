#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


Node* head = NULL;

Node* add(int data) {
    Node* new = malloc(sizeof(Node));

    // was the program able to allocate memory in heap?
    if (new == NULL)
        return NULL;

    new->data = data;

    if (head == NULL){
        head = new;
        new->next = NULL;
    } else {
        new->next = head;
        head = new;
    }

    return new;
}

Node* insert(int data, int nodeData){
    if (head == NULL){
        printf("List is empty\n");
        return NULL;
    }
    Node* current = head;
    while(current != NULL){
        if(current->data == nodeData){
            Node* new = malloc(sizeof(Node));
            // was the program able to allocate memory in heap?
            if (new == NULL)
                return NULL;
            new->data = data;
            new->next = current->next;
            current->next = new;
            return new;
        }
        current = current->next;
    }
    return NULL;
}

Node* removeNode(int data){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    Node* current = head;
    current = current->next;
    Node* before = head;

    // Remove the first Element
    if (before->data == data){
        head = before->next;
        free(before);
        return NULL;
    }
    
    // Remove following Elements
    while(current != NULL){
        if (current->data == data){
            before->next = current->next;
            free(current);
            return NULL;
        }
        current = current->next;
        before = before->next;
    }

    return -1;
}

void show_list(){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    Node* current = head;
    while(current != NULL){
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}


int save_list() {
    if (head == NULL) return -1;

    FILE *fp;
    fp = fopen("./data/linked_list.txt", "w");
    if (fp == NULL) return -2;
    
    Node* current = head;
    while(current != NULL){
        fprintf(fp, "%d\n", current->data);
        current = current->next;
    }
    fclose(fp);    
}


int load_list() {
    FILE *fp;
    fp = fopen("./data/linked_list.txt", "r");
    char line[100];
    while(!feof(fp)){
        line[0] = NULL;
        fgets(line, 100, fp);
        if (line == NULL) break;
        char *output;
        int num = strtol(line, &output, 10);
        printf("%d\n", num);
        add(num);
    }
    fclose(fp);
}