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
    printf("Can not find a Node with the data: %d\n", nodeData);
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
    printf("Can not find an Element with this data: %d\n", data);
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

void process_user_input(){
    printf("1 - Add new Node\n");
    printf("2 - Show the whole List\n");
    printf("3 - Insert a new Node\n");
    printf("4 - Delete a Node\n");
    char option;
    int user_input;
    scanf(" %c", &option);
    switch(option){
        case '1':
            printf("Enter Number you want to add: \n");
            scanf("%d", &user_input);
            add(user_input);
            break;
        case '2':
            show_list();
            break;
        case '3':
            printf("Enter Number you want to add: \n");
            scanf("%d", &user_input);
            int nodeData;
            printf("Enter the Data of the Node, where you want to insert your node after: \n");
            scanf("%d", &nodeData);
            insert(user_input, nodeData);
            break;
        case '4':
            printf("Enter Number you want to remove: \n");
            scanf("%d", &user_input);
            removeNode(user_input);
            break;
        default:
            printf("Wrong Input. Please try again.\n\n");
            break;
    }
}